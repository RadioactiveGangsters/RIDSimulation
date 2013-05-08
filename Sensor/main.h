/* 
 * File:   main.h
 * Author: Bas
 *
 */

#ifndef MAIN_H
#define	MAIN_H

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Constrained by the value of RAND_MAX*/
#define maxvalue 100

void getSensorValue(int const amount, char*const ret, unsigned int const maxval);



#endif	/* MAIN_H */

