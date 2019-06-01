#include <iostream>
#include "funcs.h"

/*
Write a program box.cpp that asks the user to input
width and height and prints a solid rectangular box
of the requested size using asterisks.
*/
void box() {
  int w, h;
  std::cout<<"Input width: ";
  std::cin>>w;
  std::cout<<"Input height: ";
  std::cin>>h;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      std::cout<<"*";
    }
    std::cout<<'\n';
  }
}

/*
Write a program checkerboard.cpp that asks the user to
input width and height and prints a rectangular checkerboard
of the requested size using asterisks and spaces (alternating).
*/

void checkerboard() {
  int w, h;
  std::cout<<"Input width: ";
  std::cin>>w;
  std::cout<<"Input height: ";
  std::cin>>h;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
        std::cout<<"*";
      }else {
        std::cout<<" ";
      }
    }
    std::cout<<'\n';
  }
}
/*
Write a program cross.cpp that asks the user to input the
shape size, and prints a diagonal cross of that dimension
*/
/*
void cross() {
  int size;
  std::cout<<"Input size: ";
  std::cin>>size;
  for(int i = size; i >= 2; i--) {
    for(int j = 0; j < size - i; j++) {
      std::cout<<" ";
    }
    std::cout<<"*";
    for(int k = 0)
  }
}

/*
Write a program lower.cpp that prints the bottom-left
half of a square, given the side length
*/

void lower() {
  int side;
  std::cout<<"Input side length: ";
  std::cin>>side;
  for(int i = 1; i <= side; i++) {
    for(int j = 0; j < i; j++){
      std::cout<<"*";
    }
    std::cout<<'\n';
  }
}

/*
Write a program upper.cpp that prints the top-right
half of a square, given the side length.
*/

void upper() {
  int side;
  std::cout<<"Input side length: ";
  std::cin>>side;
  for(int i = 0; i < side; i++){
    for(int j = 0; j < i; j++){
      std::cout<< " ";
    }
    for(int k = side; k > i; k--) {
      std::cout<<"*";
    }
    std::cout<<'\n';
  }
}

/*
Write a program trapezoid.cpp that prints an
upside-down trapezoid of given width and height.
However, if the input height is impossibly large
for the given width, then the program should
report, Impossible shape!
*/

void trapezoid() {
  int w, h;
  std::cout<<"Input width: ";
  std::cin>>w;
  std::cout<<"Input height: ";
  std::cin>>h;
  if(h > w/2) {
    std::cout<<"Impossible shape!";
  }else{
    int countheight = 0;
    for(int i = 0; i < w; i = i + 2) {
      for(int k = 0; k < i/2; k++) {
        std::cout<<" ";
      }
      for(int j = 0; j < w - i; j++){
        std::cout<<"*";
      }
      countheight++;
      if(countheight == h){
        i = w;
      }
      std::cout<<'\n';
    }
  }

}

/*
Write a program checkerboard3x3.cpp that asks the
user to input width and height and prints a
checkerboard of 3-by-3 squares. (It should work even
if the input dimensions are not a multiple of three.
*/

void checkerboard3x3() {
  int w, h;
  std::cout<<"Input width: ";
  std::cin>>w;
  std::cout<<"Input height: ";
  std::cin>>h;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++){
      if((i % 6 == 0 || i % 6 == 1 || i % 6 == 2) && (j % 6 == 0 || j % 6 == 1 || j % 6 == 2)) {
        std::cout<<"*";
      }else if((i % 6 == 3 || i % 6 == 4 || i % 6 == 5) && (j % 6 == 3 || j % 6 == 4 || j % 6 == 5)) {
        std::cout<<"*";
      }else {
        std::cout<<" ";
      }
    }
    std::cout<<'\n';
  }
}
