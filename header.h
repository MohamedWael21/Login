
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
void displayRules();
bool validPassFormat(string&, string&);
string getPassword();
void save(vector<userProfile>&);
void Login();
void encyrpt(string&);
string decyrpt(string );
bool login(vector<userProfile> &);
void changePassword(vector<userProfile>&);


#endif