/* 
 * File:   main.c
 * Author: Bas
 *
 */

#include "main.h"

int seed;
int main() 
{
    srand(time(NULL));
    seed = rand();
    int amount = 20;    
    char prev = 0;
    
    char s[amount*(numlen(maxval)+1)+1];
    
    //Temp loop to continue the run
    while(1)
    {
        getSensorValue(amount, s);
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

void getSensorValue(int amount, char*const ret)
{
    int i, j;
    int count = 0;
    char newNumber[numlen(maxval)+1];
    
    //For random generated numbers
    seed = rand();
    srand(seed);
     
    for (i = 0; i < amount; i++) 
    {
        //Get new random number between 1-100 and save in string newNumber
        itoa ( (rand()%maxval + 1), newNumber, 10 );
        for(j = 0; j < numlen(maxval); j++)
        {
            //Only if it is not empty
            if(newNumber[j] != 0)
            {
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