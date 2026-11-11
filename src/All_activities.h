#pragma once
#include "Activity.h"
#include "Calendar.h"
#include <vector>

class All_activities
{
public:
    void create_file();
    void sort_activities();
    int activities_count();
    void read_all_activities();
    void show_activities();
    void update_file();
    bool available_activity(const Activity &other);
    int conflicting_activity(const Activity &other);
    int choose_activity();

protected:
    vector<Activity> all_activities;
    Calendar cal;
};