#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "basematrix.h"
#include "matrixfunc.h"

int main()
{
    //Прямоугольная нормисная
    printf("Прямоугольная нормисная\n");
    size_t sizeX = 7;
    size_t sizeY = 8;

    int data1[sizeY][sizeX];
    initialize_rc((int *)data1, sizeY, sizeX);
    print_matrix_rc((int *)data1, sizeY, sizeX);
    printf("%d", *max_matrix_rc((int *)data1, sizeY, sizeX));

    printf("\n\n\n\n\n");
    

    //Треугольная
    printf("Треугольная\n");
    size_t size = 10;
    
    int data2[(size * (size-1))/2];
    initialize_tr(data2, size);
    print_matrix_tr(data2, size);
    printf("%d", *max_matrix_tr(data2, size));

    printf("\n\n\n\n\n");

    //Круглая
    printf("Круглая\n");
    size_t radius = 10;
    int *data3;
    initialize_cr(&data3, radius);
    print_matrix_cr(data3, radius);
    printf("%d", *max_matrix_cr(data3, radius));


    printf("\n\n\n\n\n");

    //Произвольная
    printf("Произвольная\n");
    int (*matrix_check) (int, int, size_t, size_t);
    int **data4;
    sizeX = 30;
    sizeY = 20;
    matrix_check = lines_matrix; //сюда вставляется ченибудь из matrixfunc.h
    initialize_variable(data4, sizeY, sizeX, matrix_check);
    print_matrix_variable(*data4, sizeY, sizeX, matrix_check);
    printf("%d", *max_matrix_variable(*data4, sizeY, sizeX, matrix_check));
    return 0;
}

