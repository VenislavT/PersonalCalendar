#pragma once
#include "All_activities.h"
#include "Add_activity.h"
#include "Remove_activity.h"
#include "Daily_activity.h"
#include "Change_activity.h"
#include "Find_activity.h"
#include "Busyness.h"
#include "Find_time_slot.h"
class Interface
{
public:
    void run();

private:
    All_activities collection;

};