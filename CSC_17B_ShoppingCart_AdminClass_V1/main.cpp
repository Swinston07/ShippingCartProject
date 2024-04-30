/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on March 23, 2024, 7:06 PM
 * 
 * This program is for the administrator portion of a shopping cart
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Structure

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    int size = 80;                //More space than needed
    char *itmNm = new char[size]; //Name of item
    float itmPrc;                 //Price of item
    int itmStck;                  //Stock of item
    char chckInv;                 //Decide to check inventory or not
    char newItm;                  //Decide to add new item to inventory
    int count = 0;                //List of item
    
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
            cin.ignore();
            cin.getline(itmNm,size);
            
            cout << "Input the price for the name" << endl;
            cin >>itmPrc;
            
            cout << "Input the stock of the item" << endl;
            cin >> itmStck;
            
            cout << count << setw(20) << "Name" << setw(20) << "Price"
                 << setw(20) << "Stock" << endl;
        }
    }
    
    //Map inputs to Outputs - Process
    
    //Display output
    
    //Exit stage right
    return 0;
}