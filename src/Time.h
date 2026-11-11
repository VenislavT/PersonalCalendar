#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time
{
private:
    int hour = 0, min = 0;

public:
    Time();
    Time(int hour, int min);
    int get_hour() const;
    int get_min() const;

    bool set_hour(int hour);
    bool set_min(int min);

    friend ostream &operator<<(ostream &os, const Time &time);
    friend istream &operator>>(istream &is, Time &time);
    bool input();
    bool isEqual(const Time &other) const;
    bool isLater(const Time &other) const;
    bool isEarlier(const Time &other) const;
};