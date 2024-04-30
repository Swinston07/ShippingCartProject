/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Database.h
 * Author: sterl
 *
 * Created on April 29, 2024, 12:59 PM
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <cstring>
#include<fstream>
using namespace std;

class Database{
private:
  string name;
  string userName;
  string passWord;
  string email;
  int num;
  fstream user;
 
  void setName(string); //Get the name of the user
  void setUserName(string); //Get the username of the user
  void setPassword(string); //Get the password of the user
  void setEmail(string); //Get the eamil of the user
  void writeUserInfo(int);
  void readUSerInfor(int);
  
public:
    Database(int); //Constructor
    string getName(){return name;}
    string getName(){return name;}
    string getUserName(){return userName;}
    string getPassword(){return passWord;}
    string getEmail(){return email;}
    int getNum(){return ++num;} //increment the count
};



#endif /* DATABASE_H */

