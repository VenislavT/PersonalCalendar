#include "Calendar.h"

tm to_local_time(time_t time) {
    tm result;
    localtime_s(&result, &time);
    return result;
}

bool Calendar::choose_month(int &month, int &year) {
    int current_year = to_local_time(time(0)).tm_year + 1900;

    while (true) {
        cout << "Enter a number for the month (1 to 12): ";
        cin >> month;

        cout << "Enter year (" << current_year << " or later): ";
        cin >> year;

        if (cin.fail()) {
            cin.clear();
            string word;
            cin >> word;
            if (word == "/back") {
                return false;
            }
            cin.ignore(1000, '\n');
            cout << "Month and year must be numbers!" << endl;
            continue;
        }

        if (month < 1 || month > 12) {
            cout << "Invalid. Please enter a number from 1 to 12." << endl;
            continue;
        }

        if (year < current_year) {
            cout << "Invalid year. Please enter a later year." << endl;
            continue;
        }
        break;
    }

    show_calendar(month, year);
    return true;
}

void Calendar::show_calendar(int month, int year) {
    tm first_day = { 0 };
    first_day.tm_year = year - 1900;
    first_day.tm_mon = month - 1;
    first_day.tm_mday = 1;

    time_t first_day_seconds = mktime(&first_day);
    tm first_day_local = to_local_time(first_day_seconds);

    int first_day_column = (first_day_local.tm_wday + 6) % 7;

    string days_of_week[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    int days_in_month;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    }
    else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month = 29;
        }
        else {
            days_in_month = 28;
        }
    }
    else {
        days_in_month = 31;
    }

    system("cls");
    cout << "-- Calendar for " << month << "/" << year << " --" << endl;

    cout << setfill(' ');
    for (const string& day : days_of_week) {
        cout << setw(5) << day;
    }
    cout << endl;

    for (int i = 0; i < first_day_column; ++i) {
        cout << setw(5) << "";
    }

    for (int day = 1; day <= days_in_month; ++day) {
        cout << setw(5) << day;

        if ((day + first_day_column) % 7 == 0 || day == days_in_month) {
            cout << endl;
        }
    }
}

bool Calendar::enter_week(const Date &start_date, const Date &end_date) const {
    tm start = { 0 };
    tm end = { 0 };

    start.tm_year = start_date.get_year() - 1900;
    start.tm_mon = start_date.get_month() - 1;
    start.tm_mday = start_date.get_day();

    end.tm_year = end_date.get_year() - 1900;
    end.tm_mon = end_date.get_month() - 1;
    end.tm_mday = end_date.get_day();

    time_t start_seconds = mktime(&start);
    time_t end_seconds = mktime(&end);

    tm start_local = to_local_time(start_seconds);
    tm end_local = to_local_time(end_seconds);

    return start_local.tm_wday == 1 && end_local.tm_wday == 0 && difftime(end_seconds, start_seconds) == 6 * 24 * 60 * 60;
}