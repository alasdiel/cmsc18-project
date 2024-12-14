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
#include <ctype.h>

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

We define new routes with a struct that contains the starting point,
end point, its base fare, and discounts for 2 or more passengers.
*/

typedef struct{
    char starting_point[50];
    char end_point[50];
    int base_fare;
    int discounts[2];
} Route;

// The fare matrix is defined as an array of Route structs
Route fares[] = { // formatted as: {starting_point, end_point, base_fare, {discount1, discount2}}
    //from Holy Spirit Community Hospital
    {"Holy Spirit Community Hospital", "Admin/EBL/Kalimudan/Library", 25, {5, 5}},
    {"Holy Spirit Community Hospital", "CSM", 30, {10, 5}},
    {"Holy Spirit Community Hospital", "Sports Complex", 40, {15, 5}},

    //from One Big Wash/UPad/Rehab Center
    {"One Big Wash/UPad/Rehab Center", "Admin/EBL/Kalimudan/Library", 15, {0, 0}},
    {"One Big Wash/UPad/Rehab Center", "CSM", 20, {5, 0}},
    {"One Big Wash/UPad/Rehab Center", "Sports Complex", 20, {5, 0}},

    //within the university
    {"Admin/EBL/Kalimudan/Library", "CSM", 15, {5, 0}},
    {"Admin/EBL/Kalimudan/Library", "Sports Complex", 20, {10, 0}},
    {"CSM", "Sports Complex", 15, {5, 0}},

    //from Bago Oshiro/Bureau of Plant Industries
    {"Bago Oshiro/Bureau of Plant Industries", "Admin/EBL/Kalimudan/Library", 25, {10, 0}},
    {"Bago Oshiro/Bureau of Plant Industries", "CSM", 30, {10, 5}},
    {"Bago Oshiro/Bureau of Plant Industries", "Sports Complex", 35, {10, 5}}
};

void delay (int seconds){ 
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

/*
normalize_location_name allows us to create flexible input for the user by normalizing
possible input cases to a single format
*/
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
    else if (strcmp(loc, "csm") == 0 || strcmp(loc, "college of science and mathematics") == 0 || strcmp(loc, "carim") == 0){
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
             strcmp(loc, "oshiro") == 0 ||
             strcmp(loc, "bureau of plant industries") == 0) {
        return "Bago Oshiro/Bureau of Plant Industries";
    }

    return location;
}

int calculate_fare(Route fares[], int fare_count, const char* start, const char* end, int passengers){
    const char* normalized_start = normalize_location_name(start);
    const char* normalized_end = normalize_location_name(end);

    for (int i = 0; i < fare_count; i++){
        const char* route_start = normalize_location_name(fares[i].starting_point);
        const char* route_end = normalize_location_name(fares[i].end_point);

        if (strcmp(normalized_start, route_start) == 0 && strcmp(normalized_end, route_end) == 0
            || strcmp(normalized_start, route_end) == 0 && strcmp(normalized_end, route_start) == 0){
            int fare = fares[i].base_fare;

            for (int j = 0; j < passengers - 1 && j < 2; j++){
                fare -= fares[i].discounts[j];
            }

            if (fare < minimum_fare){
                return minimum_fare;
            }

            return fare;
        }
    }
    printf("Route not found\n");
    return -1;
}


void savetofile(){

}

int main() {
    int fare_count = sizeof(fares) / sizeof(fares[0]);

    printf("Welcome to the UP Mindanao Tricycle Fare Calculator!\n");
    printf("Please input the starting point: ");
    char start[50];
    fgets(start, 50, stdin);
    start[strcspn(start, "\n")] = 0;
    printf("Please input the end point: ");
    char end[50];
    fgets(end, 50, stdin);
    end[strcspn(end, "\n")] = 0;
    printf("Please input the number of passengers: ");
    int passengers;
    scanf("%d", &passengers);

    int fare = calculate_fare(fares, fare_count, start, end, passengers);

    printf("The fare is: %d\n", fare);

    // int input;
    // do {
    //     switch(input){
    //     case 1: {
    //         calculate();
    //         }
    // }

    // } while(input != 0);

}