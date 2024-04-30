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
int readCnt(int, fstream&);
void readInv(Items *, int, fstream&);
void prntInv(Items*, int);
int editInv(Items*, int, int);
void writeCnt(int, fstream&);
void wrtInv(Items *, int, fstream&);

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
                //Read in current inventory
                cnt = readCnt(cnt, itmNum);
                readInv(item, cnt, inv);
                
                //Print  Current inventory
                cout << "Current Inventory: " << endl;
                prntInv(item, cnt);
                
                //Add items to inventory
                cnt = editInv(item, cnt, size);
                
                //Write edited inventory and number of items to file
                writeCnt(cnt, itmNum);
                wrtInv(item, cnt, inv);
                
                //Print new inventory
                cout << "New Inventory:" << endl;
                prntInv(item, cnt);
                
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
//Functions
void wrtInv(Items* itms, int n, fstream &inv){
    inv.open("Inventory.bin", ios::out | ios::binary);
                if(inv.is_open()){
                    inv.write(reinterpret_cast<char *>(itms), n*sizeof(Items));
                    inv.close();
                }
                else{
                    cout << "ERROR" << endl;
                }
}

void writeCnt(int n, fstream& num){
    num.open("NumberList.dat", ios::out);
                if(num.is_open()){
                    num << n;
                    num.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
}

int editInv(Items* itms, int n, int size){
    itms[n].itmCnt = n; //Item number
    cout << "Input the name of the item" << endl;           
    cin.ignore();
    cin.getline(itms[n].name,size);

    cout << "Input the price for the name" << endl;
    cin >> itms[n].price;

    cout << "Input the stock of the item" << endl;
    cin >> itms[n].stock;
    
    n++;
    
    return n;
}

void prntInv(Items* itms, int n){
    for(int i = 0; i < n; i++){
        cout << itms[i].itmCnt << " " << itms[i].name
             << " " << itms[i].price  << " " << itms[i].stock
             << endl;
    }
}

void readInv(Items *itm, int n, fstream &inv){
    inv.open("Inventory.bin", ios::in | ios::binary);
                if(inv.is_open()){
                    inv.read(reinterpret_cast<char *>(itm), n*sizeof(Items));
                    inv.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
}

int readCnt(int n, fstream &num){
    num.open("NumberList.dat", ios::in);
                if(num.is_open()){
                    num >> n;
                    num.close();
                }
                else{
                    cout << "ERROR!" << endl;
                }
    return n;
}

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