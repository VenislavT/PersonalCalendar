#include "Change_activity.h"

void Change_activity::change_activity() {
    read_all_activities();

    cout << "Which activity to change?" << endl;
    int index = choose_activity();
    if (index == -1) {
        return;
    }

    Activity old_activity = all_activities[index];
    all_activities.erase(all_activities.begin() + index);
    cout << endl;
    cout << "Changing: " << old_activity << endl;
    cout << endl;

    Activity new_activity = old_activity;
    cout << "Change to: " << endl;
    while (true) {
        if (!new_activity.input_date_and_time()) {
            return;
        }

        int conflict = conflicting_activity(new_activity);
        if (conflict == -1) {
            break;
        }

        cout << "Time slot is already used by: " << all_activities[conflict] << endl;
        cout << "Choose another date or time." << endl;
        cout << endl;
    }
    
    string answer;
    cout << "Do we change the person we meet with?(Y/N)?" << endl;
    cin >> answer;
    while (answer != "Y" && answer != "y" && answer != "N" && answer != "n") {
        if (answer == "/back") {
            return;
        }
        cout << "Please enter Y or N: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") {
        string new_meeting_with;
        cout << "Person to meet: ";
        cin.ignore();
        getline(cin, new_meeting_with);
        if (new_meeting_with == "/back") {
            return;
        }
        new_activity.set_meeting_with(new_meeting_with + ' ');
    }
    
    cout << "Do we change the info of the activity?(Y/N)?" << endl;
    cin >> answer;
    while (answer != "Y" && answer != "y" && answer != "N" && answer != "n") {
        if (answer == "/back") {
            return;
        }
        cout << "Please enter Y or N: ";
        cin >> answer;
    }
    if(answer == "Y" || answer == "y") {
        string new_info;
        cout << "Comment: ";
        cin.ignore();
        getline(cin, new_info);
        if (new_info == "/back") {
            return;
        }
        new_activity.set_info(new_info);
    }

    all_activities.push_back(new_activity);
    update_file();
    cout << endl;
    cout << "Done the change! New activity: " << new_activity << endl;
}