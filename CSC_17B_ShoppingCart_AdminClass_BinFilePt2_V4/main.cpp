/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on March 30, 2024, 7:30 PM
 * 
 * This program is used to create an array of Items in inventory
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

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int numItms = 10000;                //Number of items that can be stored
    int size = 1000;                    //More space than needed for item name
    Items *item = new Items[numItms];   //Array of  original items
    char chckInv;                       //Decide to check inventory or not
    char newItm;                        //Decide to add new item to inventory
    int  cnt = 0;                       //Item number
    fstream inv;                        //Inventory file
    fstream itmNum;                     //File for item number list
    
    //Initialize inputs
    
    //Decision to edit inventory or not
    do{
        cout << "Would you like to add a new item to the inventory? 'y' for Yes"
                " 'n' for No: ";
        cin >> chckInv;
    }while((chckInv != 'y' && chckInv != 'Y') && (chckInv!='n' && chckInv !='N'));
    
    //Decision to add items to the inventory
    if(chckInv == 'y' || chckInv == 'Y'){
        do{
            cout << "Would you like to add items to the inventory? 'y' for Yes 'n'"
                    " for No: ";
            cin >> newItm;
        }while((newItm != 'y' && newItm != 'Y') &&
               (newItm!='n' && newItm !='N'));
        
        //Adding Item to current inventory
        if(newItm == 'y' || newItm == 'Y'){
            while(newItm == 'y' || newItm == 'Y'){   
                //Read in current inventory
                itmNum.open("NumberList.dat", ios::in);
                if(itmNum.is_open()){
                    itmNum >> cnt;
                    itmNum.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
                
                inv.open("Inventory.bin", ios::in | ios::binary);
                if(inv.is_open()){
                    inv.read(reinterpret_cast<char *>(item), cnt*sizeof(Items));
                    inv.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
                
                cout << "Current Inventory: " << endl;
                for(int i = 0; i < cnt; i++){
                    cout << item[i].itmCnt << " " << item[i].name
                         << " " << item[i].price  << " " << item[i].stock
                         << endl;
                }
                
                item[cnt].itmCnt = cnt; //Item number
                
                cout << "Input the name of the item" << endl;           
                cin.ignore();
                cin.getline(item[cnt].name,size);

                cout << "Input the price for the name" << endl;
                cin >> item[cnt].price;

                cout << "Input the stock of the item" << endl;
                cin >> item[cnt].stock;
                
                cnt++;
                
                itmNum.open("NumberList.dat", ios::out);
                if(itmNum.is_open()){
                    itmNum << cnt;
                    itmNum.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
                
                inv.open("Inventory.bin", ios::out | ios::binary);
                if(inv.is_open()){
                    inv.write(reinterpret_cast<char *>(item), cnt*sizeof(Items));
                    inv.close();
                }
                else{
                    cout << "ERROR" << endl;
                }

                cout << "New Inventory:" << endl;
                for(int i = 0; i < cnt; i++){
                    cout << item[i].itmCnt << " " << item[i].name << " "
                         << item[i].price << " " << item[i].stock << endl;
                    }
                
                cout << "Would you like to add a new item? 'y' for Yes 'n' for No"
                     << endl;
                cin >> newItm;
            }
        }
    }
    
    //Map inputs to Outputs - Process
    
    //Display output
    
    //Close files
    
    //Delete allocated memory
     delete [] item;
    //Exit stage right
    return 0;
}