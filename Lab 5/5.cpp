#include <iostream>
using namespace std;

int sudokuboard[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},

    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},

    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

int find(int &row, int &column)
{
  for (row = 0; row < 9; row++)
  {
    for (column = 0; column < 9; column++)
    {
      if (sudokuboard[row][column] == 0)
        return 1;
    }
  }
  return 0;
}

bool recursion(int &row, int &column, int a)
{
  if (a > 9) return 0;
  for (int j = 0; j < 9; j++)
    if (sudokuboard[row][j] == a)
      return recursion(row, column, a + 1);
  for (int i = 0; i < 9; i++)
    if (sudokuboard[i][column] == a)
      return recursion(row, column, a + 1);
  int startrow = row - row % 3;
  int startcol = column - column % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (sudokuboard[startrow + i][startcol + j] == a)
        return recursion(row, column, a + 1);
  sudokuboard[row][column] = a;
  int nextrow, nextcol;
  if (!find(nextrow, nextcol))
    return 1;
  if (recursion(nextrow, nextcol, 1))
    return 1;
  sudokuboard[row][column] = 0;
  return recursion(row, column, a + 1);
}

void playgame()
{
  int row, column;
  if (!find(row, column))
  {
    cout << "game complete";
    return;
  }
  if (!recursion(row, column, 1))
    cout << "no solution possible";
}

int main()
{
  playgame();
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
      cout << sudokuboard[i][j] << " ";
    cout << endl;
  }
}
