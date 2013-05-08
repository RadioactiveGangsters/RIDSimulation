/* 
 * File:   main.c
 * Author: Bas
 *
 */

#include "main.h"

int seed;

void SetupSensors(void)
{
    srand(time(NULL));
    seed = rand();    
}

int main(void) 
{
    SetupSensors();
    int amount = 20;    
    char prev = 0;
    
    char s[amount*(numlen(maxvalue)+1)];
    
    //Temp loop to continue the run
    while(1)
    {
        getSensorValue(amount, s, maxvalue);
        
        printf("%s\n", s);
        
        //Ff c = q or EOF then quit the application
        char c = getchar();
        if(c == 'q' || c==EOF )
        {
            return 0;
        }
        //If c is \n then show new random numbers
        if(c == '\n' && prev == c)
        {
            //Double return pressed!
            break;
        }
        //Reset prev
        prev = 0; 
    }
    return 0;
}

void getSensorValue(int const amount, char*const ret, unsigned int const maxval)
{
    int i, j;
    int count = 0;
    char newNumber[numlen(maxval)+2];
    
    //For random generated numbers
    seed = rand();
    srand(seed);
    
    for (i = 0; i < amount; i++) 
    {
        //Get new random number between 1-maxval and save in string newNumber
        int randomvalue = (rand()%maxval + 1);
        snprintf(newNumber, numlen(maxval)+2, "%d", randomvalue);
        //printf("%d == %s\n",randomvalue, newNumber);
        
        j=-1;
        while(newNumber[++j]!=0)
        {
            //Only add if it is not empty
            char c = newNumber[j]; 
            ret[count] = c;  
            count++;
        }
        ret[count] = ',';
        count++;
    }
    //Add \0 to mark end of the string
    ret[count-1] = '\0';
}