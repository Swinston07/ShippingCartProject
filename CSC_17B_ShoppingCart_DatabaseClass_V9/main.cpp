/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on February 15, 2023, 2:38 PM
 */

#include <iostream>

#include "Database.h"

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    
    //Initialize inputs4
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Exit stage right
    return 0;
}

void Database::readUSerInfor(){
    user.open("User.bin", ios::out | ios::binary);
    
    user.read(reinterpret_cast<*char>(name), sizeof(name.length()));
//    user.read(reinterpret_cast<*char>(passWord), sizeof(passWord.length()));
//    user.read(reinterpret_cast<*char>(userName), sizeof(userName.length()));
//    user.raed(reinterpret_cast<*char>(email), sizeof(email.length()));
}


void Database::writeUserInfo(){
    user.open("User.bin", ios::out | ios::binary);
    
    user.write(reinterpret_cast<*char>(name), sizeof(name.length()));
    user.write(reinterpret_cast<*char>(passWord), sizeof(passWord.length()));
    user.write(reinterpret_cast<*char>(userName), sizeof(userName.length()));
    user.write(reinterpret_cast<*char>(email), sizeof(email.length()));
}

void Database::setEmail(string email){
    this->email = email;
}

void Database::setPassword(string passWord){
    this->passWord = passWord;
}

void Database::setUserName(string userName){
    this->userName = userName;
}

void Database::setName(string name){
    this->name = name;
}

Database::Database(int n){
    num = n;
    setName();
    setPassword();
    setUserName();
    setEmail();
}