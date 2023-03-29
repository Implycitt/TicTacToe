#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

void cls() {
    std::cout << "\033[2J\033[1;1H";
}

int counter = 0;
bool won = false;
std::vector<int> alrUsed;
char grid[5][5] = {
{'1', '|', '2', '|', '3'},
{'-', '-', '-', '-', '-'},
{'4', '|', '5', '|', '6'},
{'-', '-', '-', '-', '-'},
{'7', '|', '8', '|', '9'}}; 

void print() {
    cls();
    for (int i=0; i<=4; i++) {
        for (int k=0; k<=4; k++) {
            std::cout << grid[i][k];
        }
    std::cout << '\n';
  }
}

void changeElement(char num) {
  for (int i=0; i<=4; i++){
    for (int k=0; k<=4; k++) {
      if (grid[i][k] == num) {
        if (counter % 2 == 0) {
            grid[i][k] = 'O';
        } else {
            grid[i][k] = 'X';
        }
        counter++;
      }
    }
  }
}

void checkWin() {
   return 0
}

int main() { 
  print();
  std::cout << '\n' << "Please enter a number from 1-9 to mark your play in the grid: ";
  while (!won) {
    char userin;
    std::cin >> userin;
    if (std::find(alrUsed.begin(), alrUsed.end(), userin) != alrUsed.end()) {
        std::cout << "You have already entered something in this spot, try again.";
        continue;
    }
    changeElement(userin);
    print();
    alrUsed.push_back(userin);
    checkWin();
  }
  return 0;
}