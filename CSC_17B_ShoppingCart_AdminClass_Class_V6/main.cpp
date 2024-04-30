/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on March 31, 2024, 9:27 AM
 * 
 * This program is used to create an array of Items in inventory.
 
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Structure
#include "Items.h"

//Function Prototypes
char check();
char addItm();

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int numItms = 10000;                //Number of items that can be stored
    char chckInv;                       //Decide to check inventory or not
    char newItm;                        //Decide to add new item to inventory
    int  cnt = 0;                       //Item number
    Items *item = new Items(numItms);   //Array of items and details
    
    //Initialize inputs
    
    //Decision to edit inventory or not
    do{
        chckInv = check();
    }while((chckInv != 'y' && chckInv != 'Y') && (chckInv!='n' && chckInv !='N'));
    
    //Decision to add items to the inventory
    if(chckInv == 'y' || chckInv == 'Y'){
        do{
             newItm = addItm();
        }while((newItm != 'y' && newItm != 'Y') &&
               (newItm!='n' && newItm !='N'));
        
        //Adding Item to current inventory
        if(newItm == 'y' || newItm == 'Y'){
            while(newItm == 'y' || newItm == 'Y'){
                cout << "Editing inventory:" << endl;
                //Read in current inventory
               // item->readNum(cnt);
                //item->readInv(cnt);
                item->itmNum(cnt);
                
                //Print current inventory
                cout << "Current inventory:" << endl;
                item->prntInv(cnt);
                
                //Edit inventory
                item->itmNm();
                item->itmPrc();
                item->itmUnts();
                
                //Increment the item number
                cnt = item->gItmNum();
                
                //Print new inventory
                cout << "New Inventory:" << endl;
                item->prntInv(cnt);
                //item->wrtNum(cnt);
                //item->wrtInv(cnt);
                
                cout << "Would you like to add a new item? 'y' for Yes 'n' for No"
                     << endl;
                cin >> newItm;
            }
        }
    }
    
    
    //Map inputs to Outputs - Process
    
    //Display output
    
    //Delete allocated memory
     delete item;
  
    //Exit stage right
    return 0;
}
//Header functions
void Items::prntInv(int c){
    for(int i = 0; i < c; i++){
        cout << i << " " << name[i] << " " << price[i] << " " << stock[i] << endl;
    }
    cout << endl;
}

void Items::wrtInv(int c){
    inv.open("Inventory.bin", ios::out | ios::binary);
    
    if(inv.is_open()){
        for(int i = 0; i < c; i++){
            inv.write(name[i], strlen(name[i]));
            cout << "DEBUG: " << name[i] << " " << strlen(name[i]) << endl;
        }
//        inv.write(reinterpret_cast<char *>(name), c*sizeof(name));
        inv.write(reinterpret_cast<char *>(price),c*sizeof(price));
        inv.write(reinterpret_cast<char *>(stock),c*sizeof(stock));
        inv.close();
    }
    else{
        cout << "ERROR" << endl;
    }
}

void Items::wrtNum(int c){
    num.open("NumberList.dat", ios::out);
                if(num.is_open()){
                    num << c;
                    num.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
}

void Items::readInv(int c){
    inv.open("Inventory.bin", ios::in | ios::binary);
    if(inv.is_open()){
         for(int i = 0; i < c; i++){
            inv.read((char *)&nameSz[i], sizeof(int));
            cout << "DEBUG: " << name[i] << " " << strlen(name[i]) << endl;
        }
        //inv.read(reinterpret_cast<char *>(name), c*sizeof(name));
        inv.read(reinterpret_cast<char *>(price),c*sizeof(price));
        inv.read(reinterpret_cast<char *>(stock),c*sizeof(stock));
        inv.close();
    }
    else{
        cout << "EMPTY" << endl;
    }
}

void Items::readNum(int c){
    num.open("NumberList.dat", ios::in);
    
    if(num.is_open()){
        num >> c;
        num.close();
    }
    else{
        cout << "NO ITEMS" << endl;
    }
}

int Items::gItmNum(){
    return ++itmCnt;
}

void Items::itmUnts(){
     cout << "Input the number of units of the item:" << endl;
     cin >> stock[itmCnt];
}

void Items::itmPrc(){
    cout << "Input the price of the item:" << endl;
    cin >> price[itmCnt];
}


void Items::itmNm(){
    cout << "Input the name of item " << itmCnt << ":" << endl;
    name[itmCnt] = new char[length];
    cin.ignore();
    cin.getline(name[itmCnt], length-1);
    nameSz[itmCnt] = strlen(name[itmCnt]);
}

void Items::itmNum(int c){
    itmCnt = c;
}

Items::Items(int n){
    length = 100;
    size = n;
    name = new char *[size];
    price = new float[size];
    stock = new int[size];
    nameSz = new int[size];
}

//Functions
char addItm(){
    char add;
    
    cout << "Would you like to add items to the inventory? 'y' for Yes 'n'"
                    " for No: ";
    cin >> add;

    return add;
}

char check(){
    char edit;
    
    cout << "Would you like to add a new item to the inventory? 'y' for Yes"
                " 'n' for No: ";
        cin >> edit;
        
        return edit;
}