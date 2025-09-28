#include <iostream>
using namespace std;
bool safe(char **board, int N, int row, int column)
{
  for (int j = 0; j < N; j++)
    if (board[row][j] == 'Q')
      return false;

  for (int i = 0; i < N; i++)
    if (board[i][column] == 'Q')
      return false;

  for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 'Q')
      return false;

  for (int i = row, j = column; i >= 0 && j < N; i--, j++)
    if (board[i][j] == 'Q')
      return false;

  for (int i = row, j = column; i < N && j >= 0; i++, j--)
    if (board[i][j] == 'Q')
      return false;

  for (int i = row, j = column; i < N && j < N; i++, j++)
    if (board[i][j] == 'Q')
      return false;

  return true;
}

void printboard(char **board, int N)
{
  cout << "\nBoard:{\n";
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << "}";
}

void start(char **board, int N, int row)
{
  if (row == N)
  {
    cout << "\nSolution found!\n";
    printboard(board, N);
    return;
  }

  for (int column = 0; column < N; column++)
  {
    if (safe(board, N, row, column))
    {
      board[row][column] = 'Q';
      start(board, N, row + 1);

      board[row][column] = ' ';
    }
  }
}

int main()
{
  int N;
  cout << "Enter N: ";
  cin >> N;

  char **board = new char *[N];
  for (int i = 0; i < N; i++)
  {
    board[i] = new char[N];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      board[i][j] = ' ';
    }
  }
  printboard(board, N);
  start(board, N, 0);
  for (int i = 0; i < N; i++)
  {
    delete[] board[i];
  }
  delete[] board;
}
