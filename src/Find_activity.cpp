#include "Find_activity.h"

void Find_activity::find_activity() {
    read_all_activities();
    show_activities();
    cout << endl;
    
    string str;
    cout << "What to find?: ";
    getline(cin, str);
    if (str == "/back") {
        return;
    }
    cout << endl;
    
    for (char& c : str) {
        c = tolower(c);
    }
    
    bool found = false;
    cout << "Found in: " << endl;
    for (int i = 0; i < activities_count(); i++) {
        string text = all_activities[i].get_meeting_with() + " " 
            + all_activities[i].get_info();
        for (char& c : text) {
            c = tolower(c);
        }

        if (text.find(str) != string::npos) {
            cout << all_activities[i] << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No activities found." << endl;
    }
}
