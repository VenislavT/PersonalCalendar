#include "Add_activity.h"

void Add_activity::add_activity() {
    Activity new_activity;

    read_all_activities();

    cout << endl;
    cout << "Type Activity:" << endl;

    while (true) {
        if (!new_activity.input_date_and_time()) {
            return;
        }

        int conflict = conflicting_activity(new_activity);
        if (conflict == -1) {
            break;
        }

        cout << "------------------------------" << endl;
        cout << "!! Time slot NOT available. !!" << endl;
        cout << "------------------------------" << endl;
        cout << "It overlaps with: " << all_activities[conflict] << endl;
        cout << "Choose another date or time." << endl;
        cout << endl;
    }

    if (!new_activity.input_details()) {
        return;
    }

    all_activities.push_back(new_activity);
    update_file();
    cout << endl;
    cout << "Added: " << new_activity << endl;
}
