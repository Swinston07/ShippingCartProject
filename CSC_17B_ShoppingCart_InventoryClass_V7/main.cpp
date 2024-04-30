/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on February 15, 2023, 2:38 PM
 */

#include <iostream>

#include "Inventory.h"
#include <cstring>

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int numItems = 100000; //Maximum number of items to be in inventory
    int count = 0;
    char edit; //Decision to edit inventory
    Inventory **items = new Inventory*[numItems]; //Array of items in the inventory
    
    //Initialize inputs4
    cout << "Would you like to edit the inventory?\n";
    cout << "'Y' for Yes, 'n' for No" << endl;
    cin >> edit;
    
    //Map inputs to Outputs - Process
    if(edit == 'Y' || edit == 'y'){
        while(edit =='y' || edit == 'Y'){
            items[count] = new Inventory(count);
            items[count]->setName();
            items[count]->setPrice();
            items[count]->setUnits();
            count++;
            
            for(int i = 0; i < count; i++){
                cout << items[i]->getNum() << " " << items[i]->getName() << " "
                     << items[i]->getPrc() << " " << items[i]->getUnits()
                     << endl;
            }

            cout << "Do you want to add another item to the inventory?\n";
            cout << "'Y' for Yes, 'N' for No" << endl;
            cin >> edit;
        }
    }

    //Display output
    
    //Delete Allocated Memory
    for(int i = 0; i < count; i++){
        delete items[i];
    }
    
    delete [] items;
    //Exit stage right
    return 0;
}

void Inventory::setUnits(){
     cout << "Input number  the units for item " << itmNum << ": ";
     cin >> units;
}

void Inventory::setPrice(){
     cout << "Input the price of item " << itmNum << ": ";
     cin >> price;
}

void Inventory::setName(){
    cout << "Input the name of item " << itmNum << ": ";
    cin.ignore();
    getline(cin, name);
}

Inventory::Inventory(int n){
    itmNum = n;
}