#include "Find_time_slot.h"

int to_minutes(const Time& time) {
    return time.get_hour() * 60 + time.get_min();
}

Time from_minutes(int minutes) {
    return Time(minutes / 60, minutes % 60);
}

string ask_yes_no(const string& question) {
    string answer;
    cout << question;
    cin >> answer;
    while (answer != "Y" && answer != "y" && answer != "N" && answer != "n" && answer != "/back") {
        cout << "Please enter Y or N: ";
        cin >> answer;
    }
    return answer;
}

bool print_if_long_enough(int from, int to, int length) {
    if (to - from >= length) {
        cout << from_minutes(from) << " -- " << from_minutes(to) << endl;
        return true;
    }
    return false;
}

void Find_time_slot::save_date_in_certain_week() {
    read_all_activities();
    sort_activities();
    cout << endl;
    Date date1, date2;
    Time interval_start, interval_end, length;

    int month, year;
    cout << "Calendar: " << endl;
    while (true) {
        if (!cal.choose_month(month, year)) {
            return;
        }
        cout << "(type /back at any prompt to return to the menu)" << endl;
        cout << endl;

        string answer = ask_yes_no("Is the Monday of the week in this month? (Y/N): ");
        if (answer == "/back") {
            return;
        }
        if (answer == "Y" || answer == "y") {
            break;
        }
    }

    string month_text = to_string(month);
    date1.set_year(year);
    date1.set_month(month_text);

    while (true) {
        cout << "Type the Monday of the week" << endl;
        if (!date1.input_day()) {
            return;
        }
        cout << endl;

        date2 = date1;
        date2.forward_date(6);

        if (cal.enter_week(date1, date2)) {
            break;
        }
        cout << date1 << " is not a Monday. Try again." << endl;
        cout << endl;
    }

    cout << "--Start time--" << endl;
    if (!interval_start.input()) {
        return;
    }
    cout << endl;

    cout << "--End time--" << endl;
    if (!interval_end.input()) {
        return;
    }
    while (!interval_end.isLater(interval_start)) {
        cout << "End time must be later than start time." << endl;
        if (!interval_end.input()) {
            return;
        }
    }
    cout << endl;

    cout << "--Length of activity--" << endl;
    if (!length.input()) {
        return;
    }
    while (to_minutes(length) == 0) {
        cout << "Length must be more than 0." << endl;
        if (!length.input()) {
            return;
        }
    }
    cout << endl;

    cout << "First day of the week: " << date1 << endl;
    cout << "Last day of the week: " << date2 << endl;
    cout << "Available period for the activity: " << interval_start << " - " << interval_end << endl;
    cout << "Length of the activity: " << length << endl;
    cout << endl;
    cout << "-- Available intervals --" << endl;
    
    int period_start = to_minutes(interval_start);
    int period_end = to_minutes(interval_end);
    int needed = to_minutes(length);
    
    Date day = date1;

    for (int d = 0; d < 7; d++) {
        cout << "---" << day << "---" << endl;
        
        int free_from = period_start;
        bool found = false;

        for (int i = 0; i < activities_count(); i++) {
            if (!all_activities[i].get_date().isEqual(day)) {
                continue;
            }

            int activity_start = to_minutes(all_activities[i].get_start_time());
            int activity_end = to_minutes(all_activities[i].get_end_time());

            if (activity_end <= free_from || activity_start >= period_end) {
                continue;
            }

            if (print_if_long_enough(free_from, activity_start, needed)) {
                found = true;
            }
            free_from = activity_end;
        }

        if (print_if_long_enough(free_from, period_end, needed)) {
            found = true;
        }

        if (!found) {
            cout << "No free time." << endl;
        }
        cout << endl;
        day.forward_date(1);
    }
}
