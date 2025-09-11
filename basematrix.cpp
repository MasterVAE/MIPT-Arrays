#include "basematrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Прямоугольная нормисная
int *initialize_rc(int *data, size_t sizeY, size_t sizeX)
{
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            data[y * sizeX + x] = y * sizeX + x;
        }
    }
    return data;
}

void print_matrix_rc(const int *data, size_t sizeY, size_t sizeX)
{
    for(size_t y = 0; y < sizeY; y++)
    {
        for(size_t x = 0; x < sizeX; x++)
        {
            printf("[%d][%d]: %4d   ", y, x, data[y * sizeX + x]);
        }
        printf("\n");
    }
}

const int *max_matrix_rc(const int *data, size_t sizeY, size_t sizeX)
{
    const int *max = data;
    for(size_t y = 0; y < sizeY; y++)
    {
        for(size_t x = 0; x < sizeX; x++)
        {
            if(*max < data[y * sizeX + x])
            {
                max = data + y * sizeX + x;
            }
        }
    }
    return max;
}

//Треугольная
int *initialize_tr(int *data, size_t size)
{
    for(int y = 1; y < size; y++)
    {
        for(int x = 0; x < y; x++)
        {
            data[(y * (y-1))/2 + x] = y * size + x;
        }
    }
    return data;
}

void print_matrix_tr(const int *data, size_t size)
{
    for(size_t y = 1; y < size; y++)
    {
        for(size_t x = 0; x < y; x++)
        {
            printf("[%d][%d]: %4d   ", y, x, data[(y * (y-1))/2 + x]);
        }
        printf("\n");
    }
}

const int *max_matrix_tr(const int *data, size_t size)
{
    const int *max = data;
    for(size_t y = 1; y < size; y++)
    {
        for(size_t x = 0; x < y; x++)
        {
            if(*max < data[(y * (y-1))/2 + x])
            {
                max = data + (y * (y-1))/2 + x;
            }
        }
    }
    return max;
}

//Круглая
int *initialize_cr(int **data, size_t radius)
{
    assert(data != NULL);

    size_t count = 0;
    for(int y = 0; y < 2 * radius; y++)
    {
        for(int x = 0; x < 2 * radius; x++)
        {
            if((radius - y) * (radius - y) + (radius - x) * (radius - x) < radius*radius)
            {
                count++;
            } 
        }
    }
    *data = (int *)calloc(count, sizeof(int));

    assert(*data != NULL);

    count = 0;
    for(int y = 0; y < 2 * radius; y++)
    {
        for(int x = 0; x < 2 * radius; x++)
        {
            if((radius - y) * (radius - y) + (radius - x) * (radius - x) < radius*radius)
            {
                (*data)[count] = count;
                count++;
            } 
        }
    }
    return *data;
}

void print_matrix_cr(const int *data, size_t radius)
{
    assert(data != NULL);

    int count = 0;
    for(int y = 0; y < 2 * radius; y++)
    {
        for(int x = 0; x < 2 * radius; x++)
        {
            if((radius - y) * (radius - y) + (radius - x) * (radius - x) < radius*radius)
            {
                printf("%4d", data[count++]);
            } 
            else
            {
                printf("%4c", '.');
            }
        }
        printf("\n");
    }
}

const int *max_matrix_cr(const int *data, size_t radius)
{
    assert(data != NULL);

    const int *max = data;

    int count = 0;
    for(int y = 0; y < 2 * radius; y++)
    {
        for(int x = 0; x < 2 * radius; x++)
        {
            if((radius - y) * (radius - y) + (radius - x) * (radius - x) < radius*radius)
            {
                if(*max < data[count])
                {
                    max = data + count;
                }
                count++;
            } 
        }
    }
    return max;
}

//Произвольная
int *initialize_variable(int **data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t))
{
    size_t count = 0;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if(matrix_check(y, x, sizeY, sizeX))
            {
                count++;
            } 
        }
    }
    *data = (int *)calloc(count, sizeof(int));

    assert(data != NULL);
    assert(*data != NULL);

    count = 0;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if(matrix_check(y, x, sizeY, sizeX))
            {
                (*data)[count] = count;
                count++;
            } 
        }
    }
    return *data;
}

void print_matrix_variable(const int *data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t))
{
    int count = 0;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if(matrix_check(y, x, sizeY, sizeX))
            {
                printf("%4d", data[count++]);
            } 
            else
            {
                printf("%4c", '.');
            }
        }
        printf("\n");
    }
}

const int *max_matrix_variable(const int *data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t))
{
    const int *max = data;

    int count = 0;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if(matrix_check(y, x, sizeY, sizeX))
            {
                if(*max < data[count])
                {
                    max = data + count;
                }
                count++;
            } 
        }
    }
    return max;
}