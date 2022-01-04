#include <fileio.h>
using namespace std;



void mkdir(const string &filepath) {
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

void writefile(const string &filepath,const string &contents) {
	ofstream ofile(filepath,ios::trunc);
	ofile << contents;
	ofile.close();
	return;
}

bool createfile(const string &filepath,const string &contents) {
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

bool deleteline (const string &filepath,const string &delline) {
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