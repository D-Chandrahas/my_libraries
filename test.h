#ifndef TEST_H
#define TEST_H


#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstdlib>
using namespace std;



//Discards any number of preceding '\n' and one succeding '\n'. Input should have atleast one non-'\n' character. Null terminates the string
void my_getline(char* ptr){
	char c;
	while((c=getchar())=='\n'){}
	
	do{
		*ptr=c;
		ptr+=1;
	} while((c=getchar())!='\n');
	
	*ptr='\0';
	return;
}

void mkdir(const string &filepath){
	system(("mkdir " + filepath).c_str());
	return;
}

bool checkfile(const string &filepath) {
	ifstream ifile(filepath);
	if(ifile){return true;}
	else{return false;}
}

bool printfile(const string &filepath) {
	ifstream ifile(filepath);
	if(ifile){
		string temp;
		while(getline(ifile,temp)){
			cout << temp << endl;
		}
		ifile.close();
	}
	else{return false;}
	return true;
}

bool readfile(const string &filepath, string &contents) {
	ifstream ifile(filepath);
	if(ifile){
		string temp;
		contents = "";
		while(getline(ifile,temp)){
			contents = contents + temp + "\n" ;
		}
		ifile.close();
	}
	else{return false;}
	return true;
}

bool deletefile(const string &filepath) {
	return (!(bool(remove(filepath.c_str()))));
}

void writefile(const string &filepath,const string &contents="") {
	ofstream ofile(filepath,ios::trunc);
	ofile << contents;
	ofile.close();
	return;
}

bool createfile(const string &filepath,const string &contents = "") {
	ifstream ifile(filepath);
	if(!ifile){
		ifile.close();
		ofstream ofile(filepath,ios::trunc);
		ofile << contents;
		ofile.close();
	}
	else{return false;}
	return true;
}

bool appendfile(const string &filepath,const string &contents) {
	ifstream ifile(filepath);
	if(ifile){
		ifile.close();
		ofstream ofile(filepath,ios::app);
		ofile << contents;
		ofile.close();
	}
	else{return false;}
	return true;
}

bool deleteline(const string &filepath,const string &delline) {
	ifstream ifile(filepath);
	if(ifile){
		string line;
		string contents="";
		while(getline(ifile,line)){
			if(line != delline){
				contents = contents + line + "\n";
			}
		}
		ifile.close();
		ofstream ofile(filepath,ios::trunc);
		ofile << contents;
		ofile.close();
	}
	else{return false;}
	return true;
}

bool replaceline (const string &filepath,const string &delline,const string &repline) {
	ifstream ifile(filepath);
	if(ifile){
		string line;
		string contents="";
		while(getline(ifile,line)){
			if(line != delline){
				contents = contents + line + "\n";
			}
			else{contents = contents + repline + "\n";}
		}
		ifile.close();
		ofstream ofile(filepath,ios::trunc);
		ofile << contents;
		ofile.close();
	}
	else{return false;}
	return true;
}

double factorial (double n) {
	if ((remainder(n,1) != 0) or (n<0)) {return -1;}
	if (n == 0) {return 1;}
	for (int i = n-1; i >= 1; i--){
		n *= i;
	}
	return n;
}

bool isprime (const double &n) {
	for (double i = 2; i <= n/2; i++) {
		if (remainder(n,i) == 0){
			return false;
		}
	}
	if (n == 1) {return false;}
	return true;
}

int factors (const double &n) {
	int factors = 0;
	for (double i = 1; i <= n; i++) {
		if (remainder(n,i) == 0){
			factors += 1;
		}
	}
	return factors;
}

double absolute (const double &n){
	return (n<0)? (-1)*n : n;
}

double square_root (const double &n,const double &epsilon){
	double i=1;
	while(absolute((i*i)-n)>epsilon){
		i = i - (((i*i)-n)/(2*i));
	}
	return i;
}

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

void matcopy (const int &no_of_elements, float * oldmat, float * newmat) {
	for(int i=0;i<no_of_elements;i++){
		*(newmat+i) = *(oldmat+i);
	}
}

float minor (float m[3][3],const int &r,const int &c) {
	float minor;
	minor = pow((-1), r+c) * (m[(r+1)%3][(c+1)%3] * m[(r+2)%3][(c+2)%3] - m[(r+2)%3][(c+1)%3] * m[(r+1)%3][(c+2)%3]);
	return minor;
}

float cofactor (float m[3][3],const int &r,const int &c) {
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

float * transpose (const int &rows,const int &columns, float * t ) {
	static float * matrix100 = new float[rows*columns];
	for (int i=0; i<rows; i++) {
		for (int j=0; j<columns; j++) {
			//*(matrix100+(rows*j)+i) = *(t+(columns*i)+j);this line and next line do the same
			matrix100[(rows*j)+i] = *(t+(columns*i)+j);
		}
	}
	return matrix100;
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



#endif

