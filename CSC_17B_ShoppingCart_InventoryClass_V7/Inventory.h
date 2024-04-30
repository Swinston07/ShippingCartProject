/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Inventory.h
 * Author: sterl
 *
 * Created on April 23, 2024, 8:17 PM
 */
#include <cstring>
using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
private:
    int itmNum;        //Number on list item is
    int length = 100;  //Length of char array
    string name;        //Name of the item
    float price;       // Price of the item
    int units;         //Number of units for the item
public:
    
    Inventory(int);
    ~Inventory(){
        
    }
    void setName();
    void setPrice();
    void setUnits();
    int getNum(){return itmNum;}
    string getName(){return name;}
    float getPrc(){return price;}
    int getUnits(){return units;}
    void prntInv();
};



#endif /* INVENTORY_H */

