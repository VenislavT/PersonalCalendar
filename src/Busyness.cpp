#include "Busyness.h"

bool fewer_activities(const pair<Date, int>& a, const pair<Date, int>& b) {
    return a.second < b.second;
}

void Busyness::busyness()
{
    read_all_activities();
    show_activities();
    cout << endl;
    Date date1, date2;
    cout << "*Creates stats for the defined period by dates*" << endl;
    
    cout << endl;
    cout << "-- Type start date --" << endl;
    cout << endl;
    if (!date1.input()) {
        return;
    }

    cout << endl;
    cout << "-- Type end date --" << endl;
    cout << endl;
    if (!date2.input()) {
        return;
    }

    if (date1.isLater(date2)) {
        swap(date1, date2);
    }

    system("cls");
    cout << "Period: " << date1 << " - " << date2 << endl;
    cout << endl;

    sort_activities();
    vector<pair<Date, int>> stats; 
    for (int i = 0; i < activities_count(); i++) {
        Date current = all_activities[i].get_date();
        
        if (current.isEarlier(date1) || current.isLater(date2)) {
            continue;
        }

        if (!stats.empty() && stats.back().first.isEqual(current)) {
            stats.back().second++;
        }
        else {
            stats.push_back({ current, 1 });
        }
    }

    if (stats.empty()) {
        cout << "No activities found in the period." << endl;
        return;
    }

    stable_sort(stats.begin(), stats.end(), fewer_activities);

    string filename = "data/stats-" + to_string(date1.get_year()) + "-" + to_string(date1.get_month()) + "-" + to_string(date1.get_day()) + ".txt";
    ofstream file(filename);
    
    for (const pair<Date, int>& p : stats) {
        file << p.first << " --- " << p.second << endl;
        cout << p.first << " --- " << p.second << endl;
    }
    cout << endl;
    cout << "Created file: " << filename << endl;
}