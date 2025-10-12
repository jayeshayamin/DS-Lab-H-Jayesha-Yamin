#include <iostream>
using namespace std;

void enqueue(int *array, int val, int n,int& start, int &end)
{
  if (end == n - 1)
  {
    cout << "Queue full." << endl;
  }
  else
  {
    if(start==-1)
    start=0;
    end++;
    array[end] = val;
  }
}
void dequeue(int *array, int n, int &start, int &end)
{
  if (start == -1)
  {
    cout << "Queue underflow." << endl;
  }
  else
  {
    cout << "Removed: " << array[start] << endl;
    start++;
    if (start > end)
    {
      start = -1;
      end = -1;
    }
  }
}
void display(int *array, int start, int end)
{
  cout << "Displaying queue: " << endl;
  for (int i = start; i <= end; i++)
  {
    cout << array[i] << " ";
  }
}
void isemptyorfull(int start, int end, int n)
{
  if (start == -1)
  {
    cout << "Queue is empty." << endl;
  }
  else if (end == n - 1)
  {
    cout << "Queue is full." << endl;
  }
}
int main()
{
  int start = -1, end = -1;
  int n;
  cout << "Enter size of queue: ";
  cin >> n;
  int *array = new int[n];

  enqueue(array, 10, n, start, end);
  enqueue(array, 20, n, start, end);
  enqueue(array, 30, n, start, end);
  display(array, start, end);

  dequeue(array, n, start, end);
  display(array, start, end);

  isemptyorfull(start, end, n);

  delete[] array;
  return 0;
}