/*
 * Case Switch Source File
 * Feb 10 2020
 * Michael Nathan Boyd
 * mnb170030@utdallas.edu
 * CS 3377.501 Spring 2020
 * Version 1.0
 * Copyright 2020, All Rights, Reserved
 * 
 * Functions that allow for editing a file
 * to change the casing of the file and
 * to create new files.
 *
 */


#include <iostream>
#include <fstream>
#include "CaseSwitch.h"

using namespace std;

void caseUpper(string ux, string uy)
{
  cerr << "Changing Case to Upper" << endl;
  //Variable Creation and Input file Check
  char ch;
  //Opening text files
  std::ifstream infile;
  std::ofstream outfile;

  infile.open(uy.c_str());
  outfile.open(ux.c_str());
 
 //changing case and outputting results into output file
  while(!infile.eof())
    {
      infile.get(ch);
      if(ch>=97 && ch<=122)
	ch=toupper(ch);
      else;
      outfile<<ch;
    }

  //closing files
  infile.close();
  outfile.close();
  return;
}

void caseLower(string lx, string ly)
{
 cerr << "Changing Case to Lower" << endl;
 //Variable Creation and Input file Check
 char ch;
 //Opening text files
 std::ifstream infile;
 std::ofstream outfile;

 infile.open(ly.c_str());
 outfile.open(lx.c_str());

 //changing case and outputting result into output file
 while(!infile.eof())
   {
     infile.get(ch);
     if(ch>=65 && ch<=90)
       ch=tolower(ch);
     else;
     outfile<<ch;
   }

  //closing files
  infile.close();
  outfile.close();
  return;
}

void noCasing(string nx, string ny)
{
 cerr << "Copying file over." << endl;
 //Variable Creation and Input file Check
 char ch;
 //Opening text files
 std::ifstream infile;
 std::ofstream outfile;

 infile.open(ny.c_str());
 outfile.open(nx.c_str());

 //changing case and outputting result into output file
 while(!infile.eof())
   {
     infile.get(ch);
     outfile<<ch;
   }

  //closing files
  infile.close();
  outfile.close();
  return;
}
