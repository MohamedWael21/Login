/*
 * FCAI - programming 1 - 2022 - Assignment 4
 * Program Name :  main.cpp
 * Last Modification Date : 02/4/2022
 * Author1 and ID and Group:  Mohamed Wael Mohamed      20210361    S21
 * Author2 and ID and Group:  Ali Tarek Mohamed         20210245    S21
 * Author3 and ID anf Group:  Omar Mohamed Gamal        20210270    S21
 * Teaching Assistant:  Abdulrahman Abdulmonem
 * Purpose: This is LoginApp console application
 */

// include all libraries
#include <bits/stdc++.h>
#include "header.h"


using namespace std;


// main point of program
int main(){

//     cout << "=====================================================\n";
//     cout << "              Welcome to Login App!\n";
//     cout << "=====================================================\n";

// users data
vector <userProfile> user;

// load conent of file from users
loadUserData(user);

    // loop until user exit
    while(true){
        // take action from user
        takeAction(displayMenu(), user);
        for(int i = 0; i < user.size(); i++){
            cout << user[i].name << endl;
            cout << user[i].pass << endl;
            cout << user[i].email << endl;
            cout << user[i].phone << endl;

        }
      
    }


}