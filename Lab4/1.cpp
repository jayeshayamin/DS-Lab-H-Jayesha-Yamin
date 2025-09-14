#include <iostream>
using namespace std;

/*Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array*/
int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  int *array = new int[size];
  for (int i = 0; i < size; i++)
  {
    cout << "Enter value at index " << i << ": ";
    cin >> array[i];
  }
  int x;
  cout << "Enter value to find: ";
  cin >> x;

  bool flag = 0;
  for (int i = 0; i < size; i++)
  {
    if (x == array[i])
    {
      cout << x << " found at index: " << i << endl;
      flag = 1;
      break;
    }
  }
  if (flag == 0)
  {
    cout << "Element: '" << x << "' is not in the array." << endl;
  }
  delete[] array;
  return 0;
}