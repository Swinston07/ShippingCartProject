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
    int numItms = 2000;
    int size = 80;                    //More space than needed
    Items *item = new Items[numItms]; //Array of items
    char chckInv;                     //Decide to check inventory or not
    char newItm;                      //Decide to add new item to inventory
    int  cnt = 0;                     //Item number
    
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
            item[cnt].name = new char[size];
            cin.ignore();
            cin.getline(item[cnt].name,size);
            
            cout << "Input the price for the name" << endl;
            cin >>item[cnt].price;
            
            cout << "Input the stock of the item" << endl;
            cin >> item[cnt].stock;
            
            cout << item[cnt].count << " " << item[cnt].name << " "
                 << item[cnt].price << " " << item[cnt].stock << endl;
            
            item[cnt].count++;
        }
    }
    
    //Map inputs to Outputs - Process
    
    //Display output
    
    //Delete allocated memory
    
    delete [] item;
    
    //Exit stage right
    return 0;
}