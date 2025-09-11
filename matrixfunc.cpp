#include "matrixfunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int rectangle_matrix(int y, int x, size_t sizeY, size_t sizeX)
{
    return 1;
}
int sinus_matrix(int y, int x, size_t sizeY, size_t sizeX)
{
    
    if(abs(10*sin(x/10) - y) < 3)
    {
        //printf("Y: %d X: %d \n", y, x);
        return 1;
    } 
    else return 0;
}

int lines_matrix(int y, int x, size_t sizeY, size_t sizeX)
{
    
    if((x+y) % 10 < 3)
    {
        return 1;
    } 
    else return 0;
}