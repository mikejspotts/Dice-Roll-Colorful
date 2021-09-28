#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
  HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); // Gives colored text
  string player1Name, player2Name; // Initialze variables to store player names
  int player1Roll, player2Roll;    // Initialize variables to store rolls
  string player1Crit, player2Crit;

  unsigned seed;  // Random Seed Generator
  seed = time(0); // Bases seed off of system time
  srand(seed);

  cout << "Let's see who rolls the higher number! First, let's get some "
          "names...\n";

  // Gets player names from users
  cout << "Player 1, enter your name: ";
  cin >> player1Name;
  cout << "Player 2, enter your name: ";
  cin >> player2Name;

  // Repeats names back and tells them the type of die being rolled.
  cout << "\nAlright, " << player1Name << " and " << player2Name
       << "!\nRolling a twenty-sided die now...\n\n";

  // "Rolls" die for both players
  player1Roll = rand() % 20 + 1;
  player2Roll = rand() % 20 + 1;

  cout << player1Name << " rolled a " << player1Roll << "!";

  // Adds "Critical Success" or "Critical Failure" if a 20 or a 1 is rolled
  if (player1Roll == 20) {
    SetConsoleTextAttribute(screen, 10);
    cout << " Critical Success!\n\n";
    SetConsoleTextAttribute(screen, 7);
  } else if (player1Roll == 1) {
    SetConsoleTextAttribute(screen, 4);
    cout << " Critical Failure!\n\n";
    SetConsoleTextAttribute(screen, 7);
  } else {
    cout << "\n\n";
  }

  cout << player2Name << " rolled a " << player2Roll << "!";

  // Adds "Critical Success" or "Critical Failure" if a 20 or a 1 is rolled
  if (player2Roll == 20) {
    SetConsoleTextAttribute(screen, 10);
    cout << " Critical Success!\n\n";
    SetConsoleTextAttribute(screen, 7);
  } else if (player2Roll == 1) {
    SetConsoleTextAttribute(screen, 4);
    cout << " Critical Failure!\n\n";
    SetConsoleTextAttribute(screen, 7);
  } else {
    cout << "\n\n";
  }

  // Determines who is the winner (or if its a tie) and displays that to the
  // user.
  if (player1Roll > player2Roll) {
    cout << player1Name << " is the winner!\n";
  } else if (player2Roll > player1Roll) {
    cout << player2Name << " is the winner!\n";
  } else {
    cout << "Both rolls were evenly matched!\n";
  }
}
