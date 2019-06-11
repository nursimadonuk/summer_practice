#include <iostream>
#include <vector>
/*
A program that solves a sudoku puzzle. Given 9x9 2d array of numbers
the empty spaces will be represented as 0. Each row, column and 3x3
box needs to have all the numbers from 1-9 with no repetition.
The puzzle will be given by user input. And if the puzzle is
unsolvable the program will print out unsolvable. If the given array
has repeating numbers in the same row column or box the program will
print out invalid input. Or if an input is not an integer in the
range 1-9. To be able to sole a 9x9 sudoku puzzle you need at
least 17 given numbers. We will use backtracking to try every
possible answer for each box starting from the top left then see
which ones work for all the boxes. So, if we see that one box
cannot have anything in it that means that we did something wrong
in the previous steps so we will backtrack.
*/

//enum EmpOrFull {EMPTY, FULL};
int OneThruNine[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
class Box {
public:
  bool hadAnotherPossibility;
  int number;
  std::vector<int> otherPossibilities;
  int row;
  int column;
  bool given;
  Box the_box_before;
  void setGiven() {
    if()
  }
};

void fillTheBox(Box &current, Box sudoku[9][9]) {
  std::vector<int> numbersInRow;
  std::vector<int> numbersInColumn;
  std::vector<int> numbersInBox;
  int r = current.row;
  int c = current.column;
  for(int i = 0; i < 9; i++) { //goes through the column
    if(sudoku[i][c].number != 0) { //looks for the numbers in the column
      numbersInColumn.push_back(sudoku[i][c].number); //and adds to the vector
    }
  }
  for(int j = 0; j < 9; j++) { //goes through the row
    if(sudoku[r][j].number != 0) { //looks for the numbers in the row
      numbersInRow.push_back(sudoku[r][j].number); //and adds to the vector
    }
  }
  if(r == 0 || r == 1 || r == 2) {
    if(c == 0 || c == 1 || c == 2) { // in the first box
      for(int i = 0; i < 3; i++) { //chenge row numbers, go through columns
        for(int j = 0; j < 3; j++) { //change column numbers, go through rows
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 3 || c == 4 || c == 5) { //in the fourth box
      for(int i = 0; i < 3; i++) {
        for(int j = 3; j < 6; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 6 || c == 7 || c == 8) { // in the seventh box
      for(int i = 0; i < 3; i++) {
        for(int j = 6; j < 9; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }
  }else if(r == 3 || r == 4 || r == 5) {
    if(c == 0 || c == 1 || c == 2) { // in the second box
      for(int i = 3; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 3 || c == 4 || c == 5) { //in the fifth box
      for(int i = 3; i < 6; i++) {
        for(int j = 3; j < 6; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 6 || c == 7 || c == 8) { // in the eigth box
      for(int i = 3; i < 6; i++) {
        for(int j = 6; j < 9; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }
  }else if(r == 6 || r == 7 || r == 8) {
    if(c == 0 || c == 1 || c == 2) { // in the third box
      for(int i = 6; i < 9; i++) {
        for(int j = 0; j < 3; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 3 || c == 4 || c == 5) { //in the sixth box
      for(int i = 6; i < 9; i++) {
        for(int j = 3; j < 6; j++){
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }else if(c == 6 || c == 7 || c == 8) { // in the nineth box
      for(int i = 6; i < 9; i++) {
        for(int j = 6; j < 9; j++) {
          if(sudoku[i][j].number != 0) {
            numbersInBox.push_back(sudoku[i][j].number);
          }
        }
      }
    }
  }

/*
at this point all the vectors numbersInBox, numbersInRow and
numbersInColumn are all filled with the numbers that are in the
box, row or column of the specific square that we passed in as
a parameter. Now we need to fill the square with a number that is
in the array "OneThruNine" but not in those vectors. If we have
more than one number that is 1-9 and not in 3 of the vectors then
we set current.hadAnotherPossibility to true and we place the
smallest possibility to the square and add the other possibilities
to the vector otherPossibilities.
*/

  bool canbe = true;
  bool alreadyset = false;
  for(int i = 0; i < 9; i++) { //goes through the array OneThruNine
    for(int j = 0; j < numbersInColumn.size(); j++) {
      if(OneThruNine[i] == numbersInColumn[j]) { //if the number is in the column
        canbe = false; //set canbe equal to false
        j = numbersInColumn.size(); //break out from inner loop
      }
    }
    for(int j = 0; j < numbersInRow.size(); j++) { // go thru the numbers in the row
      if(canbe) { //if it wasn't in the column
        if(OneThruNine[i] == numbersInRow[j]){   //check if its in the row
          canbe = false; //if it is in the row, set canbe to false
          j = numbersInRow.size(); // break from inner loop
        }
      }
    }
    for(int j = 0; i < numbersInBox.size(); j++) {
      if(canbe) { //if it wasnt in the column or the row
        if(OneThruNine[i] == numbersInBox[j]) { //check if it is in the box
          canbe = false; //if it is in the box that means it cannot be our number
          j = numbersInBox.size(); //break from inner loop
        }
      }
    }
    //now if canbe was never set equal to false
    //then that number is a possibility
    if(canbe) {
      if(!alreadyset) {
        current.number = OneThruNine[i];
        alreadyset = true;
      }else {
        current.hadAnotherPossibility = true;
        current.otherPossibilities.push_back(OneThruNine[i]);
        //set the box before
      }
    }
  }
}

/*
write another function backtrack we will call if a square has no possibility
this function will go back and see if the squares that was filled before
had another possibility, if it did then we will change the number in that
square to the number that was in the vector otherPossibilities. We know
if a square had another possibility if the vector is not empty.
*/

void backtrack(Box &impossible) {
  if(impossible.the_box_before.otherPossibilities.size() != 0) {
      
  }
}
