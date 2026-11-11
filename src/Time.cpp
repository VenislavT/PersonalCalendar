#include "Time.h"
#include <iomanip>

Time::Time() {}

Time::Time(int hour, int min) {
    set_hour(hour);
    set_min(min);
}

int Time::get_hour() const {
    return hour;
}

int Time::get_min() const {
    return min;
}

bool Time::set_hour(int hour) {
    if (hour > 23 || hour < 0) {
        return false;
    }
    this->hour = hour;
    return true;
}

bool Time::set_min(int min) {
    if (min < 0 || min > 59) {
        return false;
    }
    this->min = min;
    return true;
}

ostream &operator<<(ostream &os, const Time &time) {
    os << setw(2) << setfill('0') << time.hour << ":" << setw(2) << setfill('0') << time.min;
    return os;
}

istream &operator>>(istream &is, Time &time) {
    is >> time.hour;
    is.ignore(1);

    is >> time.min;
    
    return is;
}

bool Time::input() {
    int new_hour;
    while (true) {
        cout << "Enter Hour: ";
        cin >> new_hour;

        if (cin.fail()) {
            cin.clear();
            string word;
            cin >> word;
            if (word == "/back") {
                cin.ignore(1000, '\n');
                return false;
            }
            cin.ignore(1000, '\n');
            cout << "Hour must be a number. Try again." << endl;
        }
        else if (!set_hour(new_hour)) {
            cout << "Hour must be from 0 to 23. Try again." << endl;
        }
        else {
            break;
        }
    }

    int new_min;
    while (true) {
        cout << "Enter Minute: ";
        cin >> new_min;

        if (cin.fail()) {
            cin.clear();
            string word;
            cin >> word;
            if (word == "/back") {
                cin.ignore(1000, '\n');
                return false;
            }
            cin.ignore(1000, '\n');
            cout << "Minute must be a number. Try again." << endl;
        }
        else if (!set_min(new_min)) {
            cout << "Minute must be from 0 to 59. Try again." << endl;
        }
        else {
            break;
        }
    }

    return true;
}

bool Time::isEqual(const Time &other) const {
    return (hour == other.hour) && (min == other.min);
}

bool Time::isLater(const Time &other) const {
    if (hour > other.hour) {
        return true;
    }

    if (hour == other.hour && min > other.min) {
        return true;
    }

    return false;
}

bool Time::isEarlier(const Time &other) const {
    if (hour < other.hour) {
        return true;
    }
    
    if (hour == other.hour && min < other.min) {
        return true;
    }

    return false;
}
