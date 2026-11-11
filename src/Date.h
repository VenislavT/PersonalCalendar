#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Date
{
private:
    int day = 1, int_month = 1, year = 1;
    string str_month = "1";
    bool is_leap_year() const;

public:
    Date();
    Date(int day, string &month, int year);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    bool set_day(int day);
    bool set_month(string &month);
    bool set_year(int year);

    friend ostream &operator<<(ostream &os, const Date &date);
    friend istream &operator>>(istream &is, Date &date);
    bool input();
    bool input_year();
    bool input_month();
    bool input_day();

    bool isEqual(const Date &other) const;
    bool isLater(const Date &other) const;
    bool isEarlier(const Date &other) const;
    void forward_date(int days);
};