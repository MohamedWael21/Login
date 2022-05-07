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

void loadUserData(vector<userProfile>& user){
    
    fstream userFile("usersdata.txt");
    while(!userFile.eof()){
        userProfile nextUser;

        userFile >> nextUser.Id;
        userFile >> nextUser.pass;
        userFile >> nextUser.email;

        user.push_back(nextUser);
    }
}

void takeAction(int choice, vector <userProfile>& user){

    switch (choice){
    case 1:
    Register(user);
        break;
    case 2:
    // Login(user);
        break;
    case 3:
    // changePass(user);
        break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }

}

void Register(vector <userProfile>& user){

    userProfile new_User;

    cout << "Enter Username or Id: ";
    cin >> new_User.Id;

    cout << "Enter Email address: ";
    cin >> new_User.email;

    cout << "Enter password: ";
    cin >> new_User.pass;

    // check if the new_user's data is valid or not
    // we will later do function named validation to check this
    user.push_back(new_User);

}