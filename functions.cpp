// All defination and implmentaion Here

// include all libraries
#include <bits/stdc++.h>
#include <conio.h>
#include "header.h"

using namespace std;

// key to encyrpt and decyrpt password
static const int KEY = 3;

//login user for change password
static  userProfile*  currentLoginUeser;

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
        userFile >> nextUser.email;
        userFile >> nextUser.pass;
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
        login(user);
        break;
    case 3:
        changePassword(user);
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

    bool isValid = false;

    userProfile new_User;

    // loop until isValid true;
    while(!isValid){
        
        string pass2{};
        cout << "Enter Username or Id: ";
        cin >> new_User.name;


        // check the name format
        if(!validNameFormat(new_User)){
            cout << "Your Name format is not valid\n";
            continue;
        }

        cout << "Enter Email address: ";
        cin >> new_User.email;

        // check the email format
        if(!validEmailFormat(new_User)){
            cout << "Your Email format is not valid" << endl;
            continue;
        }

        displayRules();

        // getPassword();
        cout << "Enter password: ";
        new_User.pass = getPassword();

        cout << "Enter password again: ";
        pass2 = getPassword();

        if(!validPassFormat(new_User.pass, pass2)) {
            continue;
        }


        cout << "Enter Phone number: ";
        cin >> new_User.phone;

        // check phone number format
         if(!validPhoneFormat(new_User)){
            cout << "Your Phone number format is not valid" << endl;
             continue;
        }

        // check if the new_user's data is registered already or not
        if(!isRegistered(user, new_User)){
            cout << "Your data is already used please enter another" << endl;
            continue;
        }

        // all is valid
        isValid = true;

    }
    // encyrpt password before store it
    encyrpt(new_User.pass);
    user.push_back(new_User);
    save(user);



}

void displayRules(){

    cout<<"password requirements: minimum 8 characters" << endl;
    cout << "it is better to be more 8 characters long" << endl;
    cout<<"password must at least include: lowercase letters , uppercase letters , digits , special characters" <<endl;
}

bool validPassFormat(string & pass, string &pass2){
    //check if user enter same password
    if(pass != pass2){
        cout << "not match with fist password\n";
        return false;
    }


    // make regex to check strong password
    regex reg("^(?=[^a-z]*[a-z])(?=[^A-Z]*[A-Z])(?=\\D*\\d)(?=.*[\\W]).*{8,}$");
    regex reg2("[a-z]*");

    //check if password match rules
    if(!regex_match(pass, reg)) {
        cout << "password is Week\n";
        displayRules();
        return false;
    }

    return true;
}

// write vector in file userdata.txt
void save(vector<userProfile>&users){
    // open file for write
    ofstream  file;

    file.open("usersdata.txt");

    if(!file.is_open()){
        cout << "not open\n";
        return;
    }

    // write all users data
    for(int i=0; i<users.size(); i++){
        file << users[i].name << " " << users[i].email << " " <<  users[i].pass << " " << users[i].phone;
    }
  
    // close file
    file.close();

    cout << "Rigestration complete\n";
}

string getPassword(){
   string password;
    int ch = _getch();
    while(ch != 13){
        if(ch == 8){
            password.pop_back();
            continue;
        }
        password.push_back(ch);
        cout << '*';
        ch = _getch();

    }
    cout << endl;

    return password;
}

// encyrpt passwords using ceaser algorithm
void encyrpt(string &password){
    // loop on all characters
    for(int i=0; i<password.size(); i++){
        // get shift charcter by key
        char encyrptedChar = (char) (password[i] + KEY) % 128;
        
        // put character in password
        password[i] = encyrptedChar;
    }
}


// decyrpt passwords
string decyrpt(string password){
    // loop on all characters
    for(int i=0; i<password.size(); i++){
        // get original character
        int code = (password[i] - KEY);
        code += 128; // to avoid negative value
        code %= 128;
        
        // put character in password
        password[i] = (char) code;
    }
    return password;
}

bool login(vector<userProfile> &users){
    // tries for login
    int tries = 3;
    while(tries--){
        //get id from user
        string id; 
        cout << "Please Enter your Id: ";
        cin >> id;

        string pass;
        // getpassword function here
        cout << "Please Enter your password: ";
        // cin >> pass;
        pass = getPassword();

        // check if user exist in system

        // search for user in vector with smae id
        for(int i=0; i<users.size(); i++){
            // found user
            if( users[i].name == id){
                
                // password is correct
                if(decyrpt(users[i].pass) == pass){
                    cout << "Successful Login, Welcome " + users[i].name + "\n";
                    currentLoginUeser = &users[i];
                    return true;
                }

            }
        }
        
         cout << "Failed login. Try again\n";
    }

     cout << "Access denied to system\n";
     return false;
   
    
}

void changePassword(vector<userProfile>&users){

    // check if user has no access
    if(!login(users)){
        return;
    }

    
    // getpassword here
    string password;
    cout << "Enter old password: ";
    // cin >> password;
    password = getPassword();

    // enter new password
    string newPassword;
    cout << "Enter new password: ";
    // cin >> newPassword;
    newPassword = getPassword();

    // enter new password again
    string password2;
    cout << "Enter password again: ";
    // cin >> password2;
    password2 = getPassword();


    if(!validPassFormat(newPassword, password2)){
        displayRules();
        return;
    }

    // envyrpt password
    encyrpt(newPassword);

    // add password to profile
    currentLoginUeser->pass = newPassword;
    
    save(users);

    cout << "Password changed successfully\n";

    
}