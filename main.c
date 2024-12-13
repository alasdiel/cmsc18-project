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
#include <string.h>

#define minimum_fare 10

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

const char* normalize_location_name(const char* location){
    char loc[50];
    strcpy(loc, location);
    for (int i = 0; loc[i]; i++){
        loc[i] = tolower(loc[i]);
    }
    if (strcmp(loc, "admin") == 0 ||
        strcmp(loc, "administration building") == 0 ||
        strcmp(loc, "chss") == 0 ||
        strcmp(loc, "ebl") == 0 ||
        strcmp(loc, "ebl dorm") == 0 ||
        strcmp(loc, "kalimudan") == 0 ||
        strcmp(loc, "kali") == 0 ||
        strcmp(loc, "library") == 0 ||
        strcmp(loc, "lib") == 0){
            return "Admin/EBL/Kalimudan/Library";
    }
    else if (strcmp(loc, "csm") == 0 || strcmp(loc, "college of science and mathematics") == 0){
        return "CSM";
    }
    else if (strcmp(loc, "sports complex") == 0 ||
             strcmp(loc, "sports com") == 0 ||
             strcmp(loc, "sports") == 0){
        return "Sports Complex";
        }
    else if (strcmp(loc, "holy spirit community hospital") == 0 ||
             strcmp(loc, "holy spirit") == 0){
        return "Holy Spirit Community Hospital";
    }
    else if (strcmp(loc, "one big wash") == 0 ||
             strcmp(loc, "upad") == 0 ||
             strcmp(loc, "rehab center") == 0||
             strcmp(loc, "rehabilitation center") == 0){
        return "One Big Wash/UPad/Rehab Center";
    }
    else if (strcmp(loc, "bago oshiro") == 0 ||
             strcmp(loc, "bureau of plant industries") == 0) {
        return "Bago Oshiro/Bureau of Plant Industries";
    }

    return location;

int calculate_fare(Route fares[], int fare_count, const char* origin, const char* destination, int passengers){
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