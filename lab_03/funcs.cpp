#include <iostream>
#include "funcs.h"
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

/*
Write a program east-storage.cpp that asks the user to
input a string representing the date (in MM/DD/YYYY format),
and prints out the East basin storage on that day.
*/

double east_storage() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()) {
    std::cerr<<"File cannot be opened for reading." << std::endl;
    exit(1);
  }else {
    std::string junk;
    getline(fin, junk);
    std::string date, input;
    double eastEl, eastSt, westEl, westSt;
    std::cout<<"Enter date: ";
    std::cin>>input;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if(date == input) {
        return eastSt;
      }
    }
  }
  fin.close();
}

/*
Write a program minmax.cpp that finds the minimum
and maximum storage in East basin in 2018.
*/

void minmax() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()) {
    std::cerr<<"File cannot be opened for reading.\n";
    exit(1);
  }else {
    std::string junk, date;
    getline(fin, junk);
    double eastEl, eastSt, westEl, westSt;
    double max = 0;
    double min = 9999999999999999;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if(eastSt > max) {
        max = eastSt;
      }
      if(eastSt < min) {
        min = eastSt;
      }
    }
    std::cout<<"minimum storage in East basin: " << min << " billion gallons.\n";
    std::cout<<"maximum storage in East basin: " << max << " billion gallons.\n";
  }
  fin.close();
}

/*
Write a program compare.cpp that asks the user to input
two dates (the beginning and the end of the interval).
The program should check each day in the interval and
report which basin had higher elevation on that day by
printing “East” or “West”, or print “Equal” if both
basins are at the same level.
*/

void compare() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()) {
    std::cerr << "File cannot be opened for reading.\n";
    exit(1);
  }else {
    std::string junk, date, input1, input2;
    double eastEl, eastSt, westEl, westSt;
    getline(fin, junk);
    std::cout<< "Enter starting date: ";
    std::cin>>input1;
    std::cout<<"Enter ending date: ";
    std::cin>>input2;
    bool start = false;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if(date == input1) {
        start = true;
      }
      if(start){
        std::cout<<date<<" ";
        if(eastEl > westEl) {
          std::cout << "East\n";
        }else if(westEl > eastEl) {
          std::cout<< "West\n";
        }else {
          std::cout<< "Equal\n";
        }
      }
      if(date == input2) {
        start = false;
      }
    }
  }
  fin.close();
}
/*
Write a program reverse-order.cpp which asks the user to
input two dates (earlier date then later date). The program
should report the West basin elevation for all days in the
interval in the reverse chronological order
(from the later date to the earlier)
*/

void reverse_order() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()) {
    std::cerr << "File cannot be opened for reading.\n";
    exit(1);
  }else {
    std::string junk, date, input1, input2;
    double eastEl, eastSt, westEl, westSt;
    getline(fin, junk);
    std::cout<<"Enter earlier date: ";
    std::cin>>input1;
    std::cout<<"Enter later date: ";
    std::cin>>input2;
    std::vector<double> vecdoub;
    std::vector<std::string> vecstr;
    bool start = false;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if(date == input1) {
        start = true;
      }
      if(start){
        vecdoub.push_back(westEl);
        vecstr.push_back(date);
      }
      if(date == input2) {
        start = false;
      }
    }
    for(int i = vecstr.size()-1; i >= 0; i--) {
      std::cout<<vecstr[i] << " " << vecdoub[i] << '\n';
    }
  }
  fin.close();
}
