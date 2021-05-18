/*
 * Casing Text
 * Feb 10 2020
 * Michael Nathan Boyd
 * mnb170030@utdallas.edu
 * CS 3377.501 Spring 2020
 * Verison 1.0
 * Copyright 2020, All Rights Reserved
 *
 * Casing Text will take an input file and change
 * all letter casing to UPPER casing or lower 
 * casing. The casing depends on what command
 * the user inputs. These inputs can be -l, -u,
 * --lower, or  --upper. There are other commands
 * as well that helps the user understand the 
 * usage of this program.
 *
 */

#include <iostream>
#include <map>
#include <tclap/CmdLine.h>
#include <tclap/SwitchArg.h>
#include <tclap/ValueArg.h>
#include <tclap/UnlabeledValueArg.h>
#include "CaseSwitch.h"

using namespace std;
enum cOptions{outfile, infile};

int main(int argc, char* argv[])
{

  //Setting up TCLAP Arguments
  TCLAP::CmdLine cmd("CS3377.501 Program 2",' ', "1.2");
  TCLAP::SwitchArg upperSwitch("u", "upper", "Convert all text to uppercase", cmd, false);
  TCLAP::SwitchArg lowerSwitch("l", "lower", "Convert all text to lowercase", cmd, false);
  TCLAP::ValueArg<std::string> outfileArg("o", "outfile", "The name of the output file", false, "output.txt", "Output filename");
  TCLAP::UnlabeledValueArg<std::string> infileArg("infile", "The inputfile name", true, "infile.txt", "input filename", false);

  //adding cmd to outfileArg and infileArg
  cmd.add(outfileArg);
  cmd.add(infileArg);
  cmd.parse(argc, argv);

  //Creating a bool to check if -u or -l is being used
  bool USwitchArg = upperSwitch.getValue();
  bool LSwitchArg = lowerSwitch.getValue();


  //Setting up map and variables
  map< cOptions, string> casingMap;
  casingMap[outfile] = outfileArg.getValue();
  casingMap[infile] = infileArg.getValue();

  //Program Start
  if(USwitchArg && LSwitchArg)
    cout << "Invalid Argument: See help page" << endl;
  else
    {
      //Checking for -u || --upper
      if(USwitchArg)
	//Calling to create file and changing letter casing
	caseUpper(casingMap[outfile].c_str(), casingMap[infile].c_str());
      else
	{
	  //Checking for -l || --lower
	  if(LSwitchArg)
	    //Calling to create file and changing letter casing
	    caseLower(casingMap[outfile].c_str(), casingMap[infile].c_str());
	  else
	    //if no arguments are called
	    noCasing(casingMap[outfile].c_str(), casingMap[infile].c_str());
	}
    }
  return 0;
}
