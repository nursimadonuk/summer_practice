#include <iostream>
#include <cmath>
#include "funcs.h"
/*
write a program that asks the user to input an integer in the
range 0 < n < 100.If the number is out of range, the program
should keep asking tore-enter until a valid number is input.
After a valid value is obtained, print this number n squared.
*/

int square(int num) {
  return pow(num, 2);
}

int valid() {
  int number;
  std::cout<<"Please enter an integer: ";
  std::cin>>number;
  std::cout<<'\n';
  while(number <= 0 || number >= 100) {
    std::cout<<"Please re-enter: ";
    std::cin>>number;
    std::cout<<'\n';
  }
  return square(number);
}

/*
write a program that asks the user to input two integers L and U
(representing the lower and upper limits of the interval), and
print out all integers in the range L ≤ i < U separated by spaces.
*/

void range(int l, int u) {
  for(int i = l; i < u; i++) {
    std::cout<< i << " ";
  }
}

void interval() {
  int l, u;
  std::cout<< "Please enter L: ";
  std::cin>>l;
  std::cout<<"Please enter U: ";
  std::cin>>u;
  range(l, u);
}

/*
Create an array myData of 10 integers. Fill all its cells with
value 1 (using a for loop).Print all elements of the array on
the screen. Ask the user to input the cell index i, and its
new value v. If the index i is within the array range (0 ≤ i < 10),
update the asked cell, myData[i] = v, and go back to the step 3.
Otherwise, if index i is out of range, the program exits.
*/

void array() {
  int arr[10];
  for(int i = 0; i < 10; i++) {
    arr[i] = 1;
  }
  int j, v;
  do {
    for(int i = 0; i < 10; i++) {
      std::cout<<arr[i]<< " ";
    }

    std::cout<< "Input index: ";
    std::cin>>j;
    std::cout<< "Input value: ";
    std::cin>>v;
    if(j >= 0 && j < 10) {
      arr[j] = v;
    }else {
      std::cout<<"Index out of range. Exit.";
    }
  }while(j >= 0 && j < 10);

}

/*
Write a program that uses an array of ints to compute
and print all Fibonacci numbers from F(0) to F(n).
*/

void fibonacci(int n) {
  int arr[n];
  arr[0] = 0;
  arr[1] = 1;
  for(int i = 2; i < n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  for(int j = 0; j < n; j++) {
    std::cout<<arr[j]<< " ";
  }
}
