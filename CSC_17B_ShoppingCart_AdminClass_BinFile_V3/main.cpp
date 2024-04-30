/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on March 23, 2024, 7:30 PM
 * 
 * This program is for the administrator portion of a shopping cart
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Structure
struct Items{
    char *name;  //Name of item
    float price;//Price of item
    int stock; //Stock of item
    int count = 0;  //List of item
};

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int numItms;
    int size = 80;                    //More space than needed
    Items item; //Array of items
    char chckInv;                     //Decide to check inventory or not
    char newItm;                      //Decide to add new item to inventory
    int  cnt = 0;                     //Item number
    fstream inv;                      //Inventory file
    
    //Initialize inputs
    
    do{
        cout << "Would you like to add a new item to the inventory? 'y' for Yes"
            " 'n' for No: ";
        cin >> chckInv;
    }while((chckInv != 'y' && chckInv != 'Y') && (chckInv!='n' && chckInv !='N'));
    
    if(chckInv == 'y' || chckInv == 'Y'){
        do{
            cout << "Would you like to add items to the inventory? 'y' for Yes 'n'"
                " for No: ";
            cin >> newItm;
        }while((newItm != 'y' && newItm != 'Y') &&
               (newItm!='n' && newItm !='N'));
        
        if(newItm == 'y' || newItm == 'Y'){
            cout << "Input the name of the item" << endl;
            item.name = new char[size];
            cin.ignore();
            cin.getline(item.name,size);
            
            cout << "Input the price for the name" << endl;
            cin >>item.price;
            
            cout << "Input the stock of the item" << endl;
            cin >> item.stock;
            
            inv.open("Inventory.bin", ios::out | ios::binary);
            inv.write(reinterpret_cast<char *>(&item.count), sizeof(item.name));
            inv.write(reinterpret_cast<char *>(item.name), sizeof(item.name));
            inv.write(reinterpret_cast<char *>(&item.price), sizeof(item.price));
            inv.write(reinterpret_cast<char *>(&item.stock), sizeof(item.stock));
            inv.close();
            
            inv.open("Inventory.bin", ios::in | ios::binary);
            inv.read(reinterpret_cast<char *>(&item.count), sizeof(item.name));
            inv.read(reinterpret_cast<char *>(item.name), sizeof(item.name));
            inv.read(reinterpret_cast<char *>(&item.price), sizeof(item.price));
            inv.read(reinterpret_cast<char *>(&item.stock), sizeof(item.stock));
            inv.close();
            
            cout << item.count << " " << item.name << " "
                 << item.price << " " << item.stock << endl;
            
            item.count++;
        }
    }
    
    //Map inputs to Outputs - Process
    
    //Display output
    
    //Close files
     inv.close();
    
    //Delete allocated memory
    
    //Exit stage right
    return 0;
}