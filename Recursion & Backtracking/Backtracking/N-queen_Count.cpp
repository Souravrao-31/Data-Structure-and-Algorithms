#include<iostream>
using namespace std;

int count = 0;

bool isSafe(int board[][11], int i, int j, int n) {
  for (int row = 0; row < i; row++) {
    if (board[row][j] == 1)
      return false;
  }
  int k = i;
  int y = j;
  while (k >= 0 && y < n) {
    if (board[k][y] == 1)
      return false;
    k--;
    y++;
  }
  k = i;
  y = j;
  while (k >= 0 && y >= 0) {
    if (board[k][y] == 1)
      return false;
    k--;
    y--;
  }
  return true;
}

bool place_queen(int board[][11], int i, int n) {
  if (i == n) {
    ++count;
    return false;
  }
  //Try to place the queen int the row
  for (int j = 0; j < n; j++) {
    if (isSafe(board, i, j, n)) {
      board[i][j] = 1;
      bool nextQueenRakhpaye = place_queen(board, i + 1, n);
      if (nextQueenRakhpaye)
        return true;
      board[i][j] = 0;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  int board[11][11] = {
    0
  };
  bool x = place_queen(board, 0, n);
  cout << count;
  return 0;
}