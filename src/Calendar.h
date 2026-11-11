#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"
using namespace std;
class Calendar
{
private:

public:
    bool choose_month(int &month, int &year);
    bool enter_week(const Date &start_date, const Date &end_date) const;
    void show_calendar(int month, int year);
};