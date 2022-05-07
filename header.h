#include <bits/stdc++.h>
using namespace std;
#ifndef HEAD
#define HEAD

// Structures delacration
struct userProfile
{
    string Id;
    string pass;
    string email;
};

// all declaration and interface
int displayMenu();
void loadUserData(vector<userProfile>&);
void takeAction(int, vector<userProfile>&);
void Register(vector <userProfile>&);
void Login();
void changePass();

#endif