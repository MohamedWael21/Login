#include <bits/stdc++.h>
using namespace std;
#ifndef HEAD
#define HEAD

// Structures delacration
struct userProfile
{
    string name;
    string pass;
    string email;
    string phone;
    vector <string> oldpasswords;
};

// all declaration and interface
int displayMenu();
void loadUserData(vector<userProfile>&);
void takeAction(int, vector<userProfile>&);
void Register(vector <userProfile>&);
bool isRegistered(vector <userProfile>, userProfile);
bool validEmailFormat(userProfile);
bool validPhoneFormat(userProfile);
bool validNameFormat(userProfile);
void Login();
void changePass();

#endif
