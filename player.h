#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

// interface for player classs
class Player{
    public:
        string first_name;
        string last_name;
        int number;
        int age;
        string position;
        string height;

};

// interface for node class
template <typename T>
class Node{
    public:
        T player;
        Node<T> *next;

};

// interface for roster class with its corresponding functions
template <typename T>
class Roster{
    private:
        Node<T> *head;

    public:
        Roster(){         // constructor
            head = NULL;
        }

        ~Roster(){   // destructor
            Node<T> *p;
            while(head != NULL){
                p = head;
                head = head->next;
                delete p;
            }
        }

        // add function to add a player to the team in order using their kit number
        void add_player(){
            Node<T> *cur;           // pointer to current node
            Node<T> *p;
            Node<T> *q;
            Node<T> *new_player = new Node<T>;   // pointer to new node
            int num;

            cout<<"First Name: ";           // getting user input
            cin>>new_player->player.first_name;
            cout<<"Last Name: ";
            cin>>new_player->player.last_name;
            cout<<"Kit Number: ";
            while (!(cin>>new_player->player.number)) {     // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout<<"Age: ";
            while (!(cin>>new_player->player.age)) {       // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            cout<<"Position: ";
            cin>>new_player->player.position;
            cout<<"Height: ";
            cin>>new_player->player.height;
            cout<<endl;

            for(q = head; q != NULL; q = q->next){        // checking if kit number has already been taking
                if(new_player->player.number == q->player.number){
                    num = q->player.number;
                    while(new_player->player.number == num){    // loop that runs until user inputs a different number
                        cout<<"This kit number has already been taken. Try again."<<endl;
                        cout<<"Kit Number: ";
                        cin>>new_player->player.number;
                        cout<<endl;
                    }
                }
            }

            for(p = head; p != NULL; p = p->next){     // checking if player already exists int the roster
                if(new_player->player.number == p->player.number && new_player->player.last_name == p->player.last_name){
                    cout<<"Player has already been added to the roster."<<endl<<endl;
                    delete new_player;
                    return;
                }
            }

            if(head == NULL || head->player.number >= new_player->player.number){   // adding new player at the head of the list if the list
                new_player->next = head;                                                 // is empty or the number of the player at the head of the
                head = new_player;                                                       // list is greater than the new player's list
                return;
            }

            cur = head;                  // adding player in the ordered list if none of the conditions above are true
            while(cur->next != NULL && cur->next->player.number < new_player->player.number){
                cur = cur->next;
            }
            new_player->next = cur->next;
            cur->next = new_player;
            
        }

        // remove function used to remove player from team roster
        void remove_player(){

            string fname, lname;   // declaring input variables
            int number;
            Node<T> *p;            // pointers to operate on the list
            Node<T> *q;
            Node<T> *r;


            cout<<"First Name: ";       // getting user input
            cin>>fname;
            cout<<"Last Name: ";
            cin>>lname;
            cout<<"Kit Number: ";
            while (!(cin>>number)) {     // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout<<endl;
    
            if(head == NULL){       // if roster is empty, prompt error message
                cout<<"The roster is empty."<<endl<<endl;
                return;
            }

            if(head->player.first_name == fname && head->player.last_name == lname && head->player.number == number){       // checking if player in question is at the head of the list
                p = head;
                head = head->next;
                cout<<p->player.first_name<<" "<<p->player.last_name<<" has been removed from the roster."<<endl<<endl;
                delete p;
                return;
            }

            for(p = head; p != NULL; p = p->next){                                              // traverse the list and removing the node containing the player
                if(p->player.first_name == fname && p->player.last_name == lname && p->player.number == number){
                    for(q = head; q != p; q = q->next){    // get to node before the node containing player that's being removed
                        r = q;
                    }
                    cout<<p->player.first_name<<" "<<p->player.last_name<<" has been removed from the roster."<<endl<<endl;
                    r->next = p->next;
                    delete p;
                    return;
                }
            }

            cout<<"Player is not in the roster."<<endl<<endl;
        }

        // function for searching a player in the team roster
        void search_roster(){
            string fname, lname;    // variables for user input
            bool found = false;     // boolean used to flag if the playe has been found in the roster

            cout<<"First Name: ";  // getting user input
            cin>>fname;
            cout<<"Last Name: ";
            cin>>lname;
            cout<<endl;

            Node<T> *p;  // pointer to operate on the list

            for(p = head; p != NULL; p = p->next){                                                      // traverse the list until player is found
                if((p->player.first_name == fname) && (p->player.last_name == lname)){
                    cout<<p->player.first_name<<"\t"<<p->player.last_name<<"\t"<<"Postition: "<<p->player.position<<" \t"<<"#"<<p->player.number<<"\t"<<"Height: "<<p->player.height<<"\t"<<"Age: "<<p->player.age<<endl;
                    found = true;  // flag meaing that player has been found
                }
            }

            if(!found){           
                cout<<"Player is not in this roster."<<endl<<endl;
            }

        }

        // function that allows the user to make changes to a specific player in the roster
        void edit_player(){
            string fname, lname, new_fname, new_lname, new_pos, new_height; // variables for user input
            int option, num, other_num, new_age, new_num;
            bool found = false;  // flag for when player has been found

            cout<<"First Name: ";      // getting user input
            cin>>fname;
            cout<<"Last Name: ";
            cin>>lname;
            cout<<"Kit Number: ";
            while (!(cin>> num)) {   // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout<<endl;

            Node<T> *p, *q;    // pointers to operate on list
            for(p = head; p != NULL; p = p->next){                                         // traverse list to find player in question
                if((p->player.first_name == fname) && (p->player.last_name == lname) && (p->player.number == num)){

                    cout<<p->player.first_name<<" "<<p->player.last_name<<endl;          // if player is found print out player information
                    cout<<"Position: "<<p->player.position<<endl;
                    cout<<"Kit Number: "<<p->player.number<<endl;
                    cout<<"Age: "<<p->player.age<<endl;
                    cout<<"Height: "<<p->player.height<<endl<<endl;

                        // starting loop that runs until user choose to stop editing a player's information
                    do{                               
                        cout<<"What would you like to edit? Select an option number below. Select 0 to finish editing."<<endl;
                        cout<<"1. Edit First Name."<<endl;
                        cout<<"2. Edit Last Name."<<endl;
                        cout<<"3. Edit Position."<<endl;
                        cout<<"4. Edit kit Number."<<endl;
                        cout<<"5. Edit Age."<<endl;
                        cout<<"6. Edit height."<<endl;

                        cin>>option;  // user input for editing option
                        cout<<endl;

                        // switch cases for different editing choice
                        switch(option){
                            case 0:
                                break;

                            case 1:    // changing a player's first name
                                cout<<"New First Name: "; 
                                cin>>new_fname;
                                cout<<p->player.first_name<<" "<<p->player.last_name<<"'s first name has been changed to "<<new_fname<<endl<<endl;
                                p->player.first_name = new_fname;
                                break;

                            case 2:  // changing player's last name
                                cout<<"New Last Name: ";
                                cin>>new_lname;
                                cout<<p->player.first_name<<" "<<p->player.last_name<<"'s last name has been changed to "<<new_lname<<endl<<endl;
                                p->player.last_name = new_lname;
                                break;

                            case 3:  // changing player's position
                                cout<<"New Position: ";
                                cin>>new_pos;
                                cout<<p->player.first_name<<" "<<p->player.last_name<<"'s position has been changed to "<<new_pos<<endl<<endl;
                                p->player.position = new_pos;
                                break;

                            case 4:   // changing player's number
                                cout<<"New Number: ";
                                while (!(cin>> new_num)) {   // checking if user input is a number
                                    cout << "Invalid input. Enter an integer number: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }

                                for(q = head; q != NULL; q = q->next){          // making sure that the new new number does not exist in the roster
                                    if(new_num == q->player.number){
                                        other_num = q->player.number;
                                        while(new_num == other_num){       
                                            cout<<"This kit number has already been taken. Try again."<<endl;
                                            cout<<"New Number: ";
                                            cin>>new_num;
                                            cout<<endl;
                                        }
                                    }
                                }
                                cout<<p->player.first_name<<" "<<p->player.last_name<<"' s number has been changed to "<<new_num<<endl<<endl;
                                p->player.number = new_num;
                                break;

                            case 5:  // changing player's age
                                cout<<"New Age: ";
                                while (!(cin>> new_age)) {        // checking if user input is a number
                                    cout << "Invalid input. Enter an integer number: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }

                                cout<<p->player.first_name<<" "<<p->player.last_name<<"'s age has been changed to "<<new_age<<endl<<endl;
                                p->player.age = new_age;
                                break;

                            case 6:  // changing player's height
                                cout<<"New Height: ";
                                cin>>new_height;
                                cout<<p->player.first_name<<" "<<p->player.last_name<<"'s height has been changed to "<<new_height<<endl<<endl;
                                p->player.height = new_height;
                                break;
                        }
                    }while(option != 0);

                    // printing the player's new information after changes has been made
                    cout<<"Player updated!"<<endl;  
                    cout<<p->player.first_name<<" "<<p->player.last_name<<endl;
                    cout<<"Position: "<<p->player.position<<endl;
                    cout<<"Kit Number: "<<p->player.number<<endl;
                    cout<<"Age: "<<p->player.age<<endl;
                    cout<<"Height: "<<p->player.height<<endl<<endl;

                    found = true;   // flaging that the player has been found in the roster
                }
            }

            if(!found){
                cout<<"Player is not in this roster."<<endl<<endl;
            }

        }

        // sort function for when a player's number has been changed using the edit function

        void sort_list(){
            Node<T> *cur = head, *next = NULL;     // pointers to operate on list
            string temp_fn, temp_ln, temp_pos, temp_h; // temporary variables to register data being swapped
            int temp_age, temp_num;

            if(head == NULL){
                return;
            }

            //traverse the list and rearrange the list
            while(cur != NULL){    
                next = cur->next;  // have the next pointer pointing to node ahead of the cur pointer
                while(next != NULL){
                    if(cur->player.number > next->player.number){      // swap if the node's number that next is pointing to is bigger than the number
                        temp_fn = cur->player.first_name;               // that cur is pointing to
                        temp_ln = cur->player.last_name;
                        temp_age = cur->player.age;
                        temp_num = cur->player.number;                              //S
                        temp_pos = cur->player.position;                            //W
                        temp_h = cur->player.height;                                //A
                                                                                    //P
                        cur->player.first_name = next->player.first_name;           //P
                        cur->player.last_name = next->player.last_name;             //I
                        cur->player.age = next->player.age;                         //N
                        cur->player.number = next->player.number;                   //G
                        cur->player.position = next->player.position;
                        cur->player.height = next->player.height;                   //I
                                                                                    //N
                        next->player.first_name = temp_fn;                          //F
                        next->player.last_name = temp_ln;                           //O
                        next->player.age = temp_age;
                        next->player.number = temp_num;
                        next->player.position = temp_pos;
                        next->player.height = temp_h;

                    }
                    next = next->next; // advancing next to the next node
                }
                cur = cur->next; // advancing cur to the next node
            }
        }

        // function to print out the roster
        void print_roster(){
            Node<T> *p;
            if(head == NULL){
                cout<<"Roster is empty."<<endl<<endl;
                return;
            }

            for(p = head; p != NULL; p = p->next){
                cout<<p->player.first_name<<"\t"<<p->player.last_name<<"\t"<<"Postition: "<<p->player.position<<" \t"<<"#"<<p->player.number<<"\t"<<"Height: "<<p->player.height<<"\t"<<"Age: "<<p->player.age<<endl;
            }
            cout<<endl;
    
        }
};

# endif