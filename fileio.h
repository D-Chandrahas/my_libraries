#ifndef FILEIO_H
#define FILEIO_H


#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>



void mkdir(const std::string &filepath);

bool checkfile(const std::string &filepath);

bool printfile(const std::string &filepath);

bool readfile(const std::string &filepath,std::string &contents);

bool deletefile(const std::string &filepath);

void writefile(const std::string &filepath,const std::string &contents="");

bool createfile(const std::string &filepath,const std::string &contents="");

bool appendfile(const std::string &filepath,const std::string &contents);

bool deleteline(const std::string &filepath,const std::string &delline);

bool replaceline(const std::string &filepath,const std::string &delline,const std::string &repline);



#endif