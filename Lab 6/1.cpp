#include <iostream>
using namespace std;

int top = -1;

void push(int *array, int val, int n)
{
  if (top == n - 1)
    cout << "Stack overflow." << endl;
  else
  {
    top++;
    array[top] = val;
  }
}

void pop(int *array)
{
  if (top == -1)
    cout << "Stack empty." << endl;
  else
    top--;
}

void peek(int *array)
{
  if (top == -1)
    cout << "Stack is empty" << endl;
  else
    cout << "Top element: " << array[top] << endl;
}

void display(int *array)
{
  if (top == -1)
    cout << "Stack is empty" << endl;
  else
  {
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
      cout << array[i] << " ";
    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter size of stack: ";
  cin >> n;
  int *array = new int[n];

  push(array, 10, n);
  push(array, 20, n);
  push(array, 30, n);
  display(array);

  peek(array);

  pop(array);
  display(array);

  delete[] array;
  return 0;
}
