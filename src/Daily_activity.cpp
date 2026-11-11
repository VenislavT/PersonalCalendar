#include "Daily_activity.h"

void Daily_activity::daily_activities() {
    Date date;
	bool found = false;

    read_all_activities();
    cout << endl;
    show_activities();
    cout << endl;
    cout << "Type Date: " << endl;
    if (!date.input()) {
        return;
    }
    cout << endl;
    cout << "-- Daily_activities for " << date << " --" << endl;

    for (int i = 0; i < activities_count(); i++) {
        if (all_activities[i].get_date().isEqual(date)) {
            cout << all_activities[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No activities for this date." << endl;
    }
}
