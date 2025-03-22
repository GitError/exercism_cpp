#pragma once
#include <string>
#include <sstream>
#include <iomanip>

namespace date_independent {
	class clock {
	private:
		int hours_;
		int minutes_;
		// Normalize time to ensure hours are in [0,23] and minutes in [0,59]
		void normalize() {
			int total_minutes = hours_ * 60 + minutes_;
			// Handle negative total minutes
			while (total_minutes < 0) {
				total_minutes += 24 * 60; // Add a full day
			}
			// Normalize to a day
			total_minutes %= (24 * 60);
			hours_ = (total_minutes / 60) % 24;
			minutes_ = total_minutes % 60;
		}
	public:
		// Static factory method to create a clock
		static clock at(int hours, int minutes) {
			return clock(hours, minutes);
		}
		// Constructor
		clock(int hours, int minutes) : hours_(hours), minutes_(minutes) {
			normalize();
		}
		// Add minutes to the clock
		clock plus(int minutes) const {
			return clock(hours_, minutes_ + minutes);
		}
		// Convert to string in "HH:MM" format
		operator std::string() const {
			std::ostringstream oss;
			oss << std::setw(2) << std::setfill('0') << hours_ << ":"
				<< std::setw(2) << std::setfill('0') << minutes_;
			return oss.str();
		}
		// Equality operator
		bool operator==(const clock& other) const {
			return hours_ == other.hours_ && minutes_ == other.minutes_;
		}
		// Inequality operator
		bool operator!=(const clock& other) const {
			return !(*this == other);
		}
	};
}
