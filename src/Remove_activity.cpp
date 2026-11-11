#include "Remove_activity.h"

void Remove_activity::remove_activity() {
    read_all_activities();

    cout << "Which activity to remove?" << endl;
    int index = choose_activity();
    if (index == -1) {
        return;
    }

    cout << endl;
    cout << "Done! Removed: " << all_activities[index] << endl;
    all_activities.erase(all_activities.begin() + index);
    update_file();
}
