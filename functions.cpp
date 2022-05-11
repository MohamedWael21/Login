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

        userFile >> nextUser.name;
        userFile >> nextUser.pass;
        userFile >> nextUser.email;
        userFile >> nextUser.phone;

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

bool isRegistered(vector <userProfile> user, userProfile new_User){

    for(int i = 0; i < user.size(); i++){
        if(user[i].name == new_User.name)
            return false;

        if(user[i].email == new_User.email)
            return false;

        if(user[i].pass == new_User.pass)
            return false;
        
        if(user[i].phone == new_User.phone)
            return false;
    }

    return true;


}

bool validEmailFormat(userProfile new_User){

    regex emailformat("^[\\w#$%‘`+&*~{|}-]+(\\.[\\w!#$%‘`+&*~{|}-]+)?@[\\w]+\\.com$");
    return regex_match(new_User.email, emailformat);

}

bool validNameFormat(userProfile new_User){

    regex nameformat("^[a-zA-Z]{2,12}([ _-]?[a-zA-Z]+)+$");
    return regex_match(new_User.name, nameformat);
}

bool validPhoneFormat(userProfile new_User){

    if(new_User.phone.size() == 11 && new_User.phone[0] == '0' && new_User.phone[1] == '1')
        return true;
        
    else
        return false;
}



void Register(vector <userProfile>& user){

    userProfile new_User;
    cout << "Enter Username or Id: ";
    cin.ignore();
    getline(cin, new_User.name);

    cout << "Enter Email address: ";
    cin >> new_User.email;

    cout << "Enter password: ";
    cin >> new_User.pass;


    cout << "Enter Phone number: ";
    cin >> new_User.phone;


    // check the name format
    if(!validNameFormat(new_User)){

        cout << "Your username format is not valid" << endl;
        Register(user);

    }


    // check the email format
    else if(!validEmailFormat(new_User)){
        cout << "Your Email format is not valid" << endl;
        Register(user);
    }

    // put here the function that check password format
    

    // check phone number format
    else if(!validPhoneFormat(new_User)){
        cout << "Your Phone number format is not valid" << endl;
        Register(user);
    }


    // check if the new_user's data is registered already or not
    else if(!isRegistered(user, new_User)){
        cout << "Your data is already used please enter another" << endl;
        Register(user);
    }


    else{
        user.push_back(new_User);
    }

}