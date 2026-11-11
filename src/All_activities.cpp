#include "All_activities.h"

const string FILE_NAME = "data/calendar.txt";

int All_activities::activities_count() {
    return (int)all_activities.size();
}

void All_activities::read_all_activities() {
    all_activities.clear();

    ifstream file(FILE_NAME);
    Activity temp_activity;

    while (file >> temp_activity) {
        all_activities.push_back(temp_activity);
    }
    
    file.close();
}

void All_activities::sort_activities() {
    for (int i = 0; i < activities_count() - 1; i++) {
        int min = i;
        for (int j = i+1; j < activities_count(); j++) {
            if ((all_activities[min].get_date().isLater(all_activities[j].get_date())) ||
                (all_activities[min].get_date().isEqual(all_activities[j].get_date()) && all_activities[min].get_start_time().isLater(all_activities[j].get_start_time()))) {
                min = j;
            }
        }
        swap(all_activities[min], all_activities[i]);
    }
}

bool All_activities::available_activity(const Activity &other) {
    return conflicting_activity(other) == -1;
}

int All_activities::conflicting_activity(const Activity &other) {
    for (int i = 0; i < activities_count(); i++) {
        if (all_activities[i].get_date().isEqual(other.get_date()) &&
            all_activities[i].get_end_time().isLater(other.get_start_time()) &&
            all_activities[i].get_start_time().isEarlier(other.get_end_time())) {
            return i;
        }
    }
    return -1;
}

int All_activities::choose_activity() {
    sort_activities();

    if (activities_count() == 0) {
        cout << "There are no activities." << endl;
        return -1;
    }

    for (int i = 0; i < activities_count(); i++) {
        cout << i + 1 << ". " << all_activities[i] << endl;
    }
    cout << endl;

    int number;
    while (true) {
        cout << "Choose activity (0 to go back): ";
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            string word;
            cin >> word;
            if (word == "/back") {
                return -1;
            }
            cin.ignore(1000, '\n');
            cout << "Please enter a number." << endl;
        }
        else if (number == 0) {
            return -1;
        }
        else if (number < 1 || number > activities_count()) {
            cout << "There is no activity with number " << number << ". Try again." << endl;
        }
        else {
            return number - 1;
        }
    }
}
 
void All_activities::show_activities() {
    sort_activities();
    cout << "-- All activities -- " << endl;
    for (int i = 0; i < activities_count(); i++) {
        cout << all_activities[i] << endl;
    }
}

void All_activities::create_file() {
    ofstream file(FILE_NAME, ios::app);
}

void All_activities::update_file() {
    sort_activities();
    
    ofstream file(FILE_NAME);  
    
    for (const auto& activity : all_activities) {
        file << activity << '\n';
    }    
    file.close();    
}
