/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: sterl
 *
 * Created on April 23, 2024, 8:14 PM
 */

#ifndef USER_H
#define USER_H

#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class User{
private:
    string userNm;   //Array of User Names
    string userPW;   //Array of User Passwords
    string userEm;   //User Email Array of user PW
    int userNum;      //User index
    fstream nameFile;
    fstream numFile;
    int nameSz;
    
public:
    User(int);
    ~User(){
       
    }
    void createAccount();
    void signIn();
    void printGreeting();
    int getNum(){return userNum;}
    string getUserNames(){return userNm;}
    string getUserPWs(){return userPW;}
    string getLogInName(){return userNm;}
    string getLogInPW(){return userPW;}
    string getEm(){return userEm;}
    bool checkPW(const string &); //Check if PW meets criteria
};



#endif /* USER_H */

