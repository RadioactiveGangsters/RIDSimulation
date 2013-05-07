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
    
    char s[amount*(numlen(maxvalue)+1)+1];
    
    //Temp loop to continue the run
    while(1)
    {
        getSensorValue(amount, s, maxvalue);
        
        printf("%s\n", s);
        
        // if c = q or EOF then quit the application
        char c = getchar();
        if(c == 'q' || c==EOF )
        {
            return 0;
        }
        // if c is \n then show new random numbers
        if(c == '\n' && prev == c)
        {
            // double return pressed!
            break;
        }
        // reset prev
        prev = 0; 
    }
    return 0;
}

void getSensorValue(int const amount, char*const ret, unsigned int const maxval)
{
    int i, j;
    int count = 0;
    char newNumber[numlen(maxval)+1];
    
    //For random generated numbers
    seed = rand();
    srand(seed);
     
    for (i = 0; i < amount; i++) 
    {
        //Get new random number between 1-maxval and save in string newNumber
        snprintf(newNumber, numlen(maxval), "%d",(rand()%maxval + 1));
        for(j = 0; j < numlen(maxval); j++)
        {
            //Only if it is not empty
            if(newNumber[j] != 0)
            {
                //Add the number to the string
                char c = newNumber[j]; 
                ret[count] = c;  
                count++;
            }
        }
        //Add , to devide the numbers in the string
        ret[count] = ',';
        count++;
    }
    ret[count-1] = NULL;
}