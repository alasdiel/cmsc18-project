/*
Main source code of the CMSC 18 Project

This project is a tricycle fare calculator for the UP Mindanao community, 
using the implemented specialized fare matrix as the point of reference 
for the prices and locations. 

The program should be able to calculate the fare from the
starting point to the end point, given a number of passengers,
and should be able to save the transaction to a save file to be
read later in a summary of the last 15 (tentative) transactions.
*/
#include <stdio.h>
#include <time.h>

#define minimum_fare 10

// //initialization of key value pairs

// char location[10][30] = {"Holy Spirit Community Hospital",
//                         "Admin",
//                         "EBL",
//                         "Kalimudan",
//                         "Library",
//                         "CSM",
//                         "Sports Complex",
//                         "One Big Wash",
//                         "UPad",
//                         "Rehab Center",
//                         "Bago Oshiro",
//                         "Bureau of Plant Industries"};
// int value[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// //end of initialization

/*
Given our matrix:                            Passengers:
Holy Spirit Community Hospital to:             1  2  3

Administration Building/EBL/Kalimudan/Library 25,20,15
CSM                                           30,20,15
Sports Complex                                40,25,20

From: One Big Wash/UPad/Rehab Center to:        
Administration Building/EBL/Kalimudan/Library 15,15,15
CSM                                           20,15,15
Sports Complex                                20,15,15

Within the University:
Admin to CSM                                  15,10,10
CSM to Sports Complex                         15,10,10
Admin to Sports Complex                       20,10,10

From: Bago Oshiro/Bureau of Plant Industries to:
Administation Building/EBL/Kalimudan/Library  25,15,15
CSM                                           30,20,15
Sports Complex                                35,25,20

We define new routes
*/

typedef struct{
    char starting_point[50];
    char end_point[50];
    int base_fare;
    int discounts[2];
} Route;


void delay (int seconds){ 
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}


void savetofile(){

}

int main() {
    int input;
    do {
        switch(input){
        case 1: {
            calculate();
            }
    }

    } while(input != 0);


}