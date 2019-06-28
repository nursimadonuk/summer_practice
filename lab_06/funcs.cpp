#include <iostream>
#include "funcs.h"

int ascii(char letter) {
  return (int)letter;
}
// task a, print out the number of the chars in a text
void test_ascii(std::string sent) {
  for(int i = 0; i < sent.size(); i++) {
    std::cout<<sent[i]<<" "<<ascii(sent[i])<<'\n';
  }
}
//helper function that shits right
char shiftChar(char c, int rshift) {
  int pos = (int)c;
  if(pos >= 65 && pos <= 90) { //this means its upper case
    pos = pos + rshift; //shift it
    if(pos >= 65 && pos <= 90) { // if it didnt come out the range
      return (char)pos;
    }else {
      int dif = pos - 90;
      int rem = dif % 26;
      int new_pos = 64 + rem;
      return new_pos;
    }
  }else if(pos >= 97 && pos <= 122) { //if its a lower case letter
    pos = pos + rshift; // add the right shift to the current position
    if(pos >= 97 && pos <= 122) { // if its still a lower case letter
      return (char)pos;
    }else {
      int dif = pos - 122;
      int rem = dif % 26;
      int new_pos = 96 + rem;
      return new_pos;
    }
  }else {
    return pos;
  }
}
//task b caeser
std::string encryptCaesar(std::string plaintext, int rshift) {
  std::string output;
  for(int i = 0; i < plaintext.size(); i++) {
    output = output + shiftChar(plaintext[i]);
  }
  return output;
}

//task c vigenere cipher
std::string encryptVigenere(std::string plaintext, std::string keyword) {
  std::string result;
  for(int i = 0; i < plaintext.size(); i++) {
    int rshift = (int)keyword[i % keyword.size()] - 96;
    result = result + encryptCaesar(plaintext[i], rshift);
  }
  return result;
}
