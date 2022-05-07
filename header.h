#include <string>
#include <vector>
using namespace std;
#ifndef HEAD
#define HEAD

// Structures delacration
struct userProfile
{
    string UserName;
    string Pass;
    string email;
};

// all declaration and interface
int displayMenu();
void takeAction(int);
void Register();
void Login();
void changePass();

#endif