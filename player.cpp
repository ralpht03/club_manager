#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

/**********************************************************
This is a program to manage a soccer team roster.
It allows a user to perform various operations on the roster.
It presents a menu of options that the user can choose from.
The user inputs a number to choose an option and the program
will continue to present the menu of option until the user
chooses to exit.
***********************************************************/
int main(){

    cout<<endl<<"**************** CLUB MANAGEMENT ****************"<<endl<<endl;

    // creating a roster object
    Roster<Player> player_roster;

    int option;

    // do while loop that displays the menu for the use to chose from
    do{
        cout<<"What operation do you want to perform. Select a number to choose an option. Select 0 to exit the page."<<endl;
        cout<<"1. Add player to team."<<endl;
        cout<<"2. Remove player from team."<<endl;
        cout<<"3. Search Player."<<endl;
        cout<<"4. Edit Player."<<endl;
        cout<<"5. Print team roster."<<endl;
        cout<<"6. Clear roster."<<endl;
        cout<<"7. Clear page."<<endl;

        while (!(cin>>option)) {       // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
        cout<<endl;

        // switch cases to perform oeration chosen by the user
        switch(option){

            case 0: 
                break;

            case 1:
                player_roster.add_player();
                break;

            case 2:
                player_roster.remove_player();
                break;
        
            case 3:
                player_roster.search_roster();
                break;

            case 4:
                player_roster.edit_player();
                player_roster.sort_list();
                break;

            case 5:
                player_roster.print_roster();
                break;

            case 6:
                player_roster.~Roster();
                break;
            case 7: 
                system("clear");
                break;
            default: 
                cout<<"Invalid option."<<endl;
        }
    }while(option != 0);

    cout<<"Bye see you next time!"<<endl;

    return 0;
}