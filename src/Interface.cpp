#include "Interface.h"

void Interface::run() {
    collection.create_file();

    while (true) {
        system("cls");
        cout << "--------Menu--------" << endl;
        cout << "1. Add activity" << endl;
        cout << "2. Remove activity" << endl;
        cout << "3. Daily activities (shows the activities for certain date)" << endl;
        cout << "4. Change activity" << endl;
        cout << "5. Search activity (searches activities by key word)" << endl;
        cout << "6. Busyness stats (creates stats by counting activities in certain period)" << endl;
        cout << "7. Find free date (finds periods to add activity in certain week)" << endl;
        cout << "0. Exit" << endl;
        cout << "--------------------" << endl;

        string choice;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        
        while (choice.size() != 1 || choice[0] < '0' || choice[0] > '7') {
            cout << "Wrong option! Choose again: ";
            cin >> choice;
            cin.ignore(1000, '\n');
        }

        if (choice == "0") {
            cout << endl;
            cout << "Ending session!" << endl;
            break;
        }

        system("cls");
    
        if (choice == "1") {
            cout << "|Add activity|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Add_activity exec;
            exec.add_activity();
        }
        else if (choice == "2") {
            cout << "|Remove activity|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Remove_activity exec;
            exec.remove_activity();
        }
        else if (choice == "3") {
            cout << "|Daily activities|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Daily_activity exec;
            exec.daily_activities();
        }
        else if (choice == "4") {
            cout << "|Change activity|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Change_activity exec;
            exec.change_activity();
        }
        else if (choice == "5") {
            cout << "|Search activity|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Find_activity exec;
            exec.find_activity();
        }
        else if (choice == "6") {
            cout << "|Busyness stats|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Busyness exec;
            exec.busyness();
        }
        else if (choice == "7") {
            cout << "|Find free date|" << endl;
            cout << "(type /back at any prompt to return to the menu)" << endl;
            Find_time_slot exec;
            exec.save_date_in_certain_week();
        }

        cout << endl;
        system("pause");
    }
}