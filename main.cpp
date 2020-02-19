//Tic Tac Toe!!!

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

//Namespace!!!

string board = "123456789";
bool player1 = true;
int place;
int turn = 0;
//Functions!!!

void winner(string player) {
  cout << "Congrats " << player << ", you won!\n";
}

void checkwin() {
  if (board[0] == 'x' && board[1] == 'x' && board[2] == 'x' || board[3] == 'x' && board[4] == 'x' && board[5] == 'x' ||
      board[6] == 'x' && board[7] == 'x' && board[8] == 'x' || board[0] == 'x' && board[3] == 'x' && board[6] == 'x' ||
      board[1] == 'x' && board[4] == 'x' && board[7] == 'x' || board[2] == 'x' && board[5] == 'x' && board[8] == 'x' ||
      board[0] == 'x' && board[4] == 'x' && board[8] == 'x' || board[2] == 'x' && board[4] == 'x' && board[6] == 'x') {
    winner("player1");
    exit(0);
  }
  else if (board[0] == 'y' && board[1] == 'y' && board[2] == 'y' || board[3] == 'y' && board[4] == 'y' && board[5] == 'y' ||
           board[6] == 'y' && board[7] == 'y' && board[8] == 'y' || board[0] == 'y' && board[3] == 'y' && board[6] == 'y' ||
           board[1] == 'y' && board[4] == 'y' && board[7] == 'y' || board[2] == 'y' && board[5] == 'y' && board[8] == 'y' ||
           board[0] == 'y' && board[4] == 'y' && board[8] == 'y' || board[2] == 'y' && board[4] == 'y' && board[6] == 'y') {
    winner("player2");
    exit(0);
  }
  else if (turn == 9) {
    cout << "Tie game!";
  }
}

void printboard() {
  cout << board[0] << " " << board[1] << " " << board[2] << endl;
  cout << board[3] << " " << board[4] << " " << board[5] << endl;
  cout << board[6] << " " << board[7] << " " << board[8] << endl;
}

void prompt1() {
  cout << "Where would player one like to place an x?" << endl;
  cin >> place;
}

void prompt2() {
  cout << "Where would player two like to place an o?" << endl;
  cin >> place;

}

void placement(int player, int spot) {
  if (spot > 9 || spot < 1) {
    cout << "Sorry, you can't place there!" << endl;
  }
  else if (board[spot-1] != 'x' && board[spot-1] != 'o') {
    if (player == 1) {
      board[spot - 1] = 'x';
      printboard();
      player1 = false;
      turn ++;
    } else if (player == 2) {
      board[spot - 1] = 'o';
      printboard();
      player1 = true;
      turn ++;
    }
  } else {
    cout << "Sorry, you can't place there!" << endl;
  }
}

int main() {

  printboard();
  cout << "Welcome to tic tac toe!" << endl;
  while (true) {
    if (player1) {
      prompt1();
      placement(1,place);

    } else if (!player1) {
      prompt2();
      placement(2,place);
    }
    checkwin();
  }


  return 0;
}

