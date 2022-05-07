// All defination and implmentaion Here

// include all libraries
#include <bits/stdc++.h>
#include "header.h"

using namespace std;


int displayMenu(){
    int choice = 0;

    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Change Password\n";
    cout << "4. Exit\n";

    cout << "Please Enter your choice ===> ";
    
    //validate input 
    while(!(cin >> choice) || choice > 4 || choice < 1){
        //clear any flags and discard any invalid character from buffer
        cin.clear();
        cin.ignore();

        cout << "Please Enter your choice ===> ";
    }
    cout << endl;
    return choice;
}

void takeAction(int choice){

    switch (choice){
    case 1:
    // Register();
        break;
    case 2:
    // Login();
        break;
    case 3:
    // changePass();
        break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }



}