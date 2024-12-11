#include <stdio.h>
#include <time.h>

//initialization of key values

char location[10][20] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
int key[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//end of initialization



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