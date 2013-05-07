/* 
 * File:   main.c
 * Author: Bas
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void getSensorValue(int amount);

int main() 
{
    int amount = 5;    
    
    getSensorValue(amount);
    
    return 0;
}

void getSensorValue(int amount)
{
    int i, j;
    int count = 0;
    char newNumber[3] = {0};
    char sensorValues[100] = {0};
    srand(time(NULL)); //For random generated numbers by time   
    for (i = 0; i < amount; i++) 
    {
        //Get new random number between 1-100 and save in string newNumber
        itoa ( (rand()%100 + 1), newNumber, 10 );
        for(j = 0; j < 3; j++)
        {
            //Only if it is not empty
            if(newNumber[j] != 0)
            {
                char c = newNumber[j]; 
                sensorValues[count] = c;  
                count++;
            }
        }
        //Add , to devide the numbers in the string
        sensorValues[count] = ',';
        count++;
    }
    printf("\nRandom Numbers: %s\n", sensorValues); 
}