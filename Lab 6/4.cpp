#include <iostream>
using namespace std;

void enqueue(int *array, int val, int &start, int &end, int n)
{
  if ((end + 1) % n == start)
  {
    cout << "Queue is full." << endl;
  }
  else
  {
    if (start == -1)
      start = 0;
    end = (end + 1) % n;
    array[end] = val;
  }
}

void dequeue(int *array, int &start, int &end, int n)
{
  if (start == -1)
  {
    cout << "Queue is empty." << endl;
  }
  else
  {
    cout << "Removed " << array[start] << endl;
    if (start == end)
    {
      start = -1;
      end = -1;
    }
    else
    {
      start = (start + 1) % n;
    }
  }
}

void display(int *array, int start, int end, int n)
{
  if (start == -1)
  {
    cout << "Queue is empty." << endl;
    return;
  }

  cout << "Queue : ";
  int i = start;
  while (true)
  {
    cout << array[i] << " ";
    if (i == end)
      break;
    i = (i + 1) % n;
  }
  cout << endl;
}

int main()
{
  int start = -1, end = -1;
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  int *array = new int[n];

  enqueue(array, 10, start, end, n);
  enqueue(array, 20, start, end, n);
  enqueue(array, 30, start, end, n);
  display(array, start, end, n);

  dequeue(array, start, end, n);
  display(array, start, end, n);

  enqueue(array, 40, start, end, n);
  display(array, start, end, n);

  delete[] array;
  return 0;
}
