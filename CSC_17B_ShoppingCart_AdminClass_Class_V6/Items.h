/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Items.h
 * Author: sterl
 *
 * Created on March 30, 2024, 9:37 PM
 */

#include <fstream>

#ifndef ITEMS_H
#define ITEMS_H

class Items{
private:
    char **name;    //Name of item
    float *price;   //Price of item
    int *stock;     //Stock of item
    int itmCnt;     //Item number list
    int size;
    int length;
    int *nameSz;
    fstream inv;
    fstream num;
public:
    Items(int);
    ~Items(){
        for(int i = 0; i < itmCnt; i++){
            delete name[i];
        }
        delete [] name;
        delete [] price;
        delete [] stock;
        delete [] nameSz;
    }
    
    void itmNm();
    void itmPrc();
    void itmUnts();
    void itmNum(int);
    int gItmNum();
    void readNum(int);
    void readInv(int);
    void wrtNum(int);
    void wrtInv(int);
    void prntInv(int);
    //void nameSz(int);
    char **gNm();
    float *gPrc();
    int *gStck();
   
};


#endif /* ITEMS_H */

