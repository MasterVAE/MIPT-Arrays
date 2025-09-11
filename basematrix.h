#ifndef BASEMATRIX_H_
#define BASEMATRIX_H_

#include <stdlib.h>

int *initialize_rc(int*data, size_t sizeY, size_t sizeX);
void print_matrix_rc(const int *data, size_t sizeY, size_t sizeX);
const int *max_matrix_rc(const int*data, size_t sizeY, size_t sizeX);

int *initialize_tr(int*data, size_t size);
void print_matrix_tr(const int *data, size_t size);
const int *max_matrix_tr(const int*data, size_t size);

int *initialize_cr(int **data, size_t radius);
void print_matrix_cr(const int *data, size_t radius);
const int *max_matrix_cr(const int *data, size_t radius);

int *initialize_variable(int **data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t));
void print_matrix_variable(const int *data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t));
const int *max_matrix_variable(const int *data, size_t sizeY, size_t sizeX, int (*matrix_check) (int, int, size_t, size_t));

#endif //BASEMATRIX