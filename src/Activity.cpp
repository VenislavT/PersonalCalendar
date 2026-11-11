#include "Activity.h"
Activity::Activity() {
}

Activity::Activity(Date date, Time start_time, Time end_time, string meeting_with, string info) {
    set_date(date);
    set_start_time(start_time);
    set_end_time(end_time);
    set_meeting_with(meeting_with);
    set_info(info);
}

ostream &operator<<(ostream &os, const Activity &activity) {
    os << activity.date << " | " << activity.start_time << " - " << activity.end_time << " | " << activity.meeting_with << "| " << activity.info;
    return os;
}

istream &operator>>(istream &is, Activity &activity) {
    is >> activity.date;
    is.ignore(3);
    is >> activity.start_time;
    is.ignore(3);
    is >> activity.end_time;
    is.ignore(3);

    getline(is>>ws, activity.meeting_with, '|');
    getline(is>>ws, activity.info);

    return is;
}

bool Activity::input_date_and_time() {
    cout << "--Date--" << endl;
    if (!date.input()) {
        return false;
    }
    cout << endl;

    cout << "--Start time--" << endl;
    if (!start_time.input()) {
        return false;
    }
    cout << endl;

    cout << "--End time--" << endl;
    if (!end_time.input()) {
        return false;
    }
    while (!end_time.isLater(start_time)) {
        cout << "End time must be after start time. Try again!" << endl;
        if (!end_time.input()) {
            return false;
        }
    }
    cout << endl;

    return true;
}

bool Activity::input_details() {
    cout << "--Meeting with--" << endl;
    cout << "Enter person/people: ";
    cin.ignore();
    getline(cin, meeting_with);
    if (meeting_with == "/back") {
        return false;
    }
    meeting_with = meeting_with + ' ';
    cout << endl;

    cout << "--Information--" << endl;
    cout << "Information about the activity: ";
    getline(cin, info);
    if (info == "/back") {
        return false;
    }

    return true;
}

Date Activity::get_date() const {
    return date;
}

Time Activity::get_start_time() const {
    return start_time;
}

Time Activity::get_end_time() const {
    return end_time;
}

string Activity::get_info() const {
    return info;
}

string Activity::get_meeting_with() const {
    return meeting_with;
}

void Activity::set_date(const Date &other) {
    this->date = other;
}

void Activity::set_start_time(const Time &other) {
    this->start_time = other;
}

void Activity::set_end_time(const Time &other) {
    this->end_time = other;
}

void Activity::set_info(const string &other) {
    this->info = other;
}

void Activity::set_meeting_with(const string &other) {
    this->meeting_with = other;
}

void Activity::forward_start_time(const Time &other) {
    int new_hour, new_min, count;
    new_min = other.get_min() + start_time.get_min();
    count = new_min / 60;
    new_min %= 60;

    new_hour = other.get_hour() + start_time.get_hour() + count;
    count = new_hour / 24;
    new_hour %= 24;
    set_start_time(Time(new_hour, new_min));
    date.forward_date(count);
}

void Activity::forward_end_time(const Time &other) {
    int new_hour, new_min, count;
    new_min = other.get_min() + end_time.get_min();
    count = new_min / 60;
    new_min %= 60;

    new_hour = other.get_hour() + end_time.get_hour() + count;
    count = new_hour / 24;
    new_hour %= 24;
    set_end_time(Time(new_hour, new_min));
    date.forward_date(count);
}
