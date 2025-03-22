#include "meetup.h"

namespace meetup {

    using namespace boost::gregorian;

    scheduler::scheduler(greg_month month, unsigned int year)
        : month_(month), year_(year) {
    }

    // Helper method to find a teenth day
    date scheduler::find_teenth(greg_weekday weekday) const {
        // Start with the 13th of the month
        date start_date(year_, month_, 13);

        // Calculate days to add to get to the desired weekday
        int days_diff = weekday.as_number() - start_date.day_of_week().as_number();
        if (days_diff < 0) days_diff += 7;

        // Return the date of the teenth day with the requested weekday
        return start_date + days(days_diff);
    }

    // Helper method to find nth occurrence of a weekday
    date scheduler::find_nth_weekday(greg_weekday weekday, int n) const {
        // Start with the first day of the month
        date start_date(year_, month_, 1);

        // Calculate days to add to get to the first occurrence of the weekday
        int days_to_first = weekday.as_number() - start_date.day_of_week().as_number();
        if (days_to_first < 0) days_to_first += 7;

        // Calculate the date of the nth occurrence
        return start_date + days(days_to_first + (n - 1) * 7);
    }

    // Helper method to find the last occurrence of a weekday
    date scheduler::find_last_weekday(greg_weekday weekday) const {
        // Get the last day of the month
        date end_of_month = date(year_, month_, 1) + months(1) - days(1);

        // Calculate days to subtract to get to the last occurrence of the weekday
        int days_diff = end_of_month.day_of_week().as_number() - weekday.as_number();
        if (days_diff < 0) days_diff += 7;

        // Return the date of the last occurrence of the weekday
        return end_of_month - days(days_diff);
    }

    // Teenth implementations
    date scheduler::monteenth() const { return find_teenth(Monday); }
    date scheduler::tuesteenth() const { return find_teenth(Tuesday); }
    date scheduler::wednesteenth() const { return find_teenth(Wednesday); }
    date scheduler::thursteenth() const { return find_teenth(Thursday); }
    date scheduler::friteenth() const { return find_teenth(Friday); }
    date scheduler::saturteenth() const { return find_teenth(Saturday); }
    date scheduler::sunteenth() const { return find_teenth(Sunday); }

    // First weekday implementations
    date scheduler::first_monday() const { return find_nth_weekday(Monday, 1); }
    date scheduler::first_tuesday() const { return find_nth_weekday(Tuesday, 1); }
    date scheduler::first_wednesday() const { return find_nth_weekday(Wednesday, 1); }
    date scheduler::first_thursday() const { return find_nth_weekday(Thursday, 1); }
    date scheduler::first_friday() const { return find_nth_weekday(Friday, 1); }
    date scheduler::first_saturday() const { return find_nth_weekday(Saturday, 1); }
    date scheduler::first_sunday() const { return find_nth_weekday(Sunday, 1); }

    // Second weekday implementations
    date scheduler::second_monday() const { return find_nth_weekday(Monday, 2); }
    date scheduler::second_tuesday() const { return find_nth_weekday(Tuesday, 2); }
    date scheduler::second_wednesday() const { return find_nth_weekday(Wednesday, 2); }
    date scheduler::second_thursday() const { return find_nth_weekday(Thursday, 2); }
    date scheduler::second_friday() const { return find_nth_weekday(Friday, 2); }
    date scheduler::second_saturday() const { return find_nth_weekday(Saturday, 2); }
    date scheduler::second_sunday() const { return find_nth_weekday(Sunday, 2); }

    // Third weekday implementations
    date scheduler::third_monday() const { return find_nth_weekday(Monday, 3); }
    date scheduler::third_tuesday() const { return find_nth_weekday(Tuesday, 3); }
    date scheduler::third_wednesday() const { return find_nth_weekday(Wednesday, 3); }
    date scheduler::third_thursday() const { return find_nth_weekday(Thursday, 3); }
    date scheduler::third_friday() const { return find_nth_weekday(Friday, 3); }
    date scheduler::third_saturday() const { return find_nth_weekday(Saturday, 3); }
    date scheduler::third_sunday() const { return find_nth_weekday(Sunday, 3); }

    // Fourth weekday implementations
    date scheduler::fourth_monday() const { return find_nth_weekday(Monday, 4); }
    date scheduler::fourth_tuesday() const { return find_nth_weekday(Tuesday, 4); }
    date scheduler::fourth_wednesday() const { return find_nth_weekday(Wednesday, 4); }
    date scheduler::fourth_thursday() const { return find_nth_weekday(Thursday, 4); }
    date scheduler::fourth_friday() const { return find_nth_weekday(Friday, 4); }
    date scheduler::fourth_saturday() const { return find_nth_weekday(Saturday, 4); }
    date scheduler::fourth_sunday() const { return find_nth_weekday(Sunday, 4); }

    // Last weekday implementations
    date scheduler::last_monday() const { return find_last_weekday(Monday); }
    date scheduler::last_tuesday() const { return find_last_weekday(Tuesday); }
    date scheduler::last_wednesday() const { return find_last_weekday(Wednesday); }
    date scheduler::last_thursday() const { return find_last_weekday(Thursday); }
    date scheduler::last_friday() const { return find_last_weekday(Friday); }
    date scheduler::last_saturday() const { return find_last_weekday(Saturday); }
    date scheduler::last_sunday() const { return find_last_weekday(Sunday); }
}