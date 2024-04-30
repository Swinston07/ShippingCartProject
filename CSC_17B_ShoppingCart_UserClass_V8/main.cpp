/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on February 15, 2023, 2:38 PM
 */

#include <iostream>
#include <cstring>
#include <string.h>

#include "User.h"

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int numUsers = 100000;
    User **user = new User*[numUsers];
    int count = 0;
    char exist; //Character y or n to determine an existing user
    string logName; //Log in name
    string logPW;  //Log in password
    bool isVal = false; //Check if log in and password combo is valid
    string userName[numUsers]; //Array of created user names sized count
    string userPW[numUsers];   //Array of user PWs sized count
    
    //Initialize inputs4
    cout << "Are you an existing user? 'Y' for 'Yes,' 'N' for 'No': ";
    cin >> exist;
    
    switch(exist){
//        case 'Y': user->signIn();
//                  break;
//                  
//        case 'y': user->signIn();
//                  break;
                  
        case 'N': //Create new account    
                  user[count] = new User(count);
                  
                  do{
                      user[count]->createAccount();

                      for(int i = 0; i<=count; i++){ //Check if Email is already taken
                            if(i!=count && user[count]->getEm().compare(user[i]->getEm())==0){
                                isVal=false; //Email already in use
                                i=count; //exit for loop

                                cout << "Email already in use. Please enter a new Email";
                                cout << endl << endl;
                            }
                            else{
                                isVal=true;
                            }
                        }
                        
                      isVal = false;
                      
                      for(int i = 0; i<=count; i++){ //Check if UserName is already taken
                            if(i!=count && user[count]->getUserNames().compare(user[i]->getUserNames())==0){
                                isVal=false; //UserName already in use
                                i=count; //exit for loop

                                cout << "User Name already in use. Please enter a new Email";
                                cout << endl << endl;
                            }
                            else{
                                isVal=true;
                            }
                        }
                  }while(isVal==false);
                      
                      isVal = false;
                      
                  //Sign in after creating account
                  do{
                      user[count]->signIn();

                       //Check to see if login name and password match  
                      logName = user[count]->getLogInName();
                      logPW   = user[count]->getLogInPW();

                      count++;
                      
                      for(int i = 0; i < count; i++){
                          userName[i] = user[i]->getUserNames();
                          userPW[i]   = user[i]->getUserPWs();

                          //Compare login name and password to username and password database
                          if(logName.compare(userName[i])==0 && logPW.compare(userPW[i])==0){
                              isVal = true; //login name and pass word combo is valid
                              i = count; //exit for loop
                          }
                      }
                      
                      (isVal == false)?count-- : count = count;
                      (isVal == false)?cout << "Incorrect use name or password\n":
                                       cout << "Welcome " << logName << "!" << endl;
                  }while(isVal==false);
                  
                  break;
                  
        case 'n': //Create new account    
                  user[count] = new User(count);
                  
                  do{
                      user[count]->createAccount();

                      for(int i = 0; i<=count; i++){ //Check if Email is already taken
                            if(i!=count && user[count]->getEm().compare(user[i]->getEm())==0){
                                isVal=false; //Email already in use
                                i=count; //exit for loop

                                cout << "Email already in use. Please enter a new Email";
                                cout << endl << endl;
                            }
                            else{
                                isVal=true;
                            }
                        }
                        
                      isVal = false;
                      
                      for(int i = 0; i<=count; i++){ //Check if UserName is already taken
                            if(i!=count && user[count]->getUserNames().compare(user[i]->getUserNames())==0){
                                isVal=false; //UserName already in use
                                i=count; //exit for loop

                                cout << "User Name already in use. Please enter a new Email";
                                cout << endl << endl;
                            }
                            else{
                                isVal=true;
                            }
                        }
                  }while(isVal==false);
                      
                      isVal = false;
                      
                  //Sign in after creating account
                  do{
                      user[count]->signIn();

                       //Check to see if login name and password match  
                      logName = user[count]->getLogInName();
                      logPW   = user[count]->getLogInPW();

                      count++;             
                      for(int i = 0; i < count; i++){
                          userName[i] = user[i]->getUserNames();
                          userPW[i]   = user[i]->getUserPWs();

                          //Compare login name and password to username and password database
                          if(logName.compare(userName[i])==0 && logPW.compare(userPW[i])==0){
                              isVal = true; //login name and pass word combo is valid
                              i = count; //exit for loop
                          }
                      }
                      
                      (isVal == false)? count-- : count = count;
                      (isVal == false)?cout << "Incorrect use name or password\n":
                                       cout << "Welcome " << logName << "!" << endl;
                  }while(isVal==false);
                  break;    
    }
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Delete allocated memory
    for(int i = 0; i < count; i++){
        delete user[i];
    }
    
    delete [] user;
    
    //Exit stage right
    return 0;
}

//Existing user function
void User::signIn(){
    int index;

        cout << "Input your user name: ";
        cin >> userNm;
        cout << endl;

        cout << "Input your password: ";
        cin >> userPW;
        cout << endl;

    cout << endl;
}

//Create account function
bool User::checkPW(const string &PW){
    int minLength = 8;
    int maxLength = 16;
    bool lengthStat = false; //Length requirement
    bool upperStat  = false; //Needs at least one upper case
    bool lowerStat  = false; //Needs at least one lower case
    bool digitStat  = false; //Needs at least one digit
    
    //Check if password meets length requirements
    lengthStat = (PW.length() >= minLength && PW.length() <= maxLength)?true:false;
    
    //Check wach letter in the password
    for(char letter:PW){
        if(isdigit(letter)){
            digitStat = true;
        }
        if(isupper(letter)){
            upperStat = true;
        }
        if(islower(letter)){
            lowerStat = true;
        }
    }
    
    return (lengthStat && digitStat && upperStat && lowerStat);
 
}
void User::createAccount(){
     bool valid;
     bool match;
     string verify;
//    do{ //Create Email; do while entered email matches one already in use
        cout << "Input your email: ";
        cin >> userEm;
        cout << endl;
    
        cout << "Input your user name: ";
        cin >> userNm;
        cout << endl;
    
    do{ //Create Password; do while password verification doesn't match
        cout <<"Input your password: ";
        cin >> userPW;
        cout << endl;

        cout << "Re-enter password: ";
        cin >> verify;
        cout << endl;

        match = (verify.compare(userPW)==0) ? true : false;
        
        valid = checkPW(userPW); //Check if password is valid
        
        if(!valid){
            cout << "Invalid Password" << endl;
        }
    }while(match == false || valid == false);
}

//Constructor
User::User(int n){
    userNum = n;
}