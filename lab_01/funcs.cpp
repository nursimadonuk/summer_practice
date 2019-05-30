#include <iostream>
#include "funcs.h"

//return smaller of the two
int smaller(int a, int b) {
  if(a > b) {
    return b;
  }else {
    return a;
  }
}


//return smaller of the 3
int smallest(int a, int b, int c) {
  if(a > b) {
    if(c > b) {
      return b;
    }else {
      return c;
    }
  }else {
    if(c > a) {
      return a;
    }else {
      return c;
    }
  }
}

//takes in an integer as a year and telles if its a leap year or not
std::string leap(int year) {
  if(year % 4 != 0) {
    return "Common year";
  }else if(year % 100 != 0) {
    return "Leap year";
  }else if(year % 400 != 0) {
    return "Common year";
  }else {
    return "Leap year";
  }
}

//given the month and year, return the number of days in that month
int numOfDays(int m, int year) {
  if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
    return 31;
  }else if(m == 4 || m == 6 || m == 9 || m == 11) {
    return 30;
  }else if(m == 2){
    if(leap(year) == "Leap year") {
      return 29;
    }else {
      return 28;
    }
  }else {
    return 0;
  }
}
