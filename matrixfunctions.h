//#include "C:/Users/vishnu/Desktop/c/my_functions/matrixfunctions.h"
//or #include <myfunctions.h> environment variable CPLUS_INCLUDE_PATH
#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H


#include <cmath>
#include <iostream>



void printmat (const int &rows, const int &columns, float * mat_ptr);

void scanmat (const int &rows, const int &columns, float * mat_ptr);

void matcopy (const int &elements, float * oldmat, float * newmat);

float minor (float m[3][3], const int &r, const int &c);

float cofactor (float m[3][3], const int &r, const int &c);

float det (float m[3][3]);

void transpose (const int &rows,const int &columns, float *old, float *neu);

float * adjoint (float m[3][3]);

float * inversemat (float m[3][3]); 



#endif


