#pragma once

#include <string>
#include <iomanip>
#include <sstream>

namespace date_independent {
    class clock {
    private:
        int hours_;
        int minutes_;
        void normalize() {
            int total_minutes = hours_ * 60 + minutes_;
            while (total_minutes < 0) {
                total_minutes += 24 * 60;
            }
            total_minutes %= (24 * 60);
            hours_ = (total_minutes / 60) % 24;
            minutes_ = total_minutes % 60;
        }

    public:
        static clock at(int hours, int minutes) {
            return clock(hours, minutes);
        }
        clock(int hours, int minutes) : hours_(hours), minutes_(minutes) {
            normalize();
        }
        clock plus(int minutes) const {
            return clock(hours_, minutes_ + minutes);
        }
        operator std::string() const {
            std::ostringstream oss;
            oss << std::setw(2) << std::setfill('0') << hours_ << ":"
                << std::setw(2) << std::setfill('0') << minutes_;
            return oss.str();
        }
        bool operator==(const clock& other) const {
            return hours_ == other.hours_ && minutes_ == other.minutes_;
        }
        bool operator!=(const clock& other) const {
            return !(*this == other);
        }
    };
}