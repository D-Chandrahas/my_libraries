#include <matrixfunctions.h>
using namespace std;


void printmat (const int &rows, const int &columns, float * mat_ptr) {
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout << *mat_ptr << " ";
			mat_ptr++;
		}
		cout << endl;
	}
}

void scanmat (const int &rows, const int &columns, float * mat_ptr) {
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cin >> *mat_ptr;
			mat_ptr++;
		}
	}
}

void matcopy (const int &elements, float * oldmat, float * newmat) {
	for(int i=0;i<elements;i++){
		*(newmat+i) = *(oldmat+i);
	}
}

float minor (float m[3][3], const int &r, const int &c) {
	float minor;
	minor = pow((-1), r+c) * (m[(r+1)%3][(c+1)%3] * m[(r+2)%3][(c+2)%3] - m[(r+2)%3][(c+1)%3] * m[(r+1)%3][(c+2)%3]);
	return minor;
}

float cofactor (float m[3][3], const int &r, const int &c) {
	float cofactor;
	cofactor = m[(r+1)%3][(c+1)%3] * m[(r+2)%3][(c+2)%3] - m[(r+2)%3][(c+1)%3] * m[(r+1)%3][(c+2)%3];
	return cofactor;
}

float det (float m[3][3]) {
	float det=0;
	for(int i=0;i<3;i++){
		det += m[0][i] * cofactor (m,0,i);
	}
	return det;
}

void transpose (const int &rows,const int &columns,const float *old, float *neu) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<columns; j++) {
			//*(matrix100+(rows*j)+i) = *(t+(columns*i)+j);this line and next line do the same
			neu[(rows*j)+i] = old[(columns*i)+j];
		}
	}
	return ;
}

float * adjoint (float m[3][3]) {
	static float matrix101[3][3];
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			matrix101[i][j] = cofactor (m,j,i);
		}
	}
	return *matrix101;
}

float * inversemat (float m[3][3]) {
	static float error1[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	if (det(m) == 0) {return *error1;}

	static float matrix102[3][3];
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			matrix102[i][j] = cofactor(m,j,i) / det(m);
		}
	}
	return *matrix102;
}

