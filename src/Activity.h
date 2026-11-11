#pragma once
#include "Time.h"
#include "Date.h"

class Activity
{
public:
    Activity();
    Activity(Date date, Time start_time, Time end_time, string meeting_with, string info);
    friend ostream &operator<<(ostream &os, const Activity &activity);
    friend istream &operator>>(istream &os, Activity &activity);
    bool input_date_and_time();
    bool input_details();

    Date get_date() const;
    Time get_start_time() const;
    Time get_end_time() const;
    string get_info() const;
    string get_meeting_with() const;

    void set_date(const Date &other);
    void set_start_time(const Time &other);
    void set_end_time(const Time &other);
    void set_info(const string &other);
    void set_meeting_with(const string &other);

    void forward_start_time(const Time &other);
    void forward_end_time(const Time &other);

private:
    Date date;
    Time start_time, end_time;
    string info;
    string meeting_with;
};