#include <iostream>
using namespace std;

/*Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user*/

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
  cout << "\nUnSorted Array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }

  for (int i = 0; i < size-1; i++)
  {
    int min = i;
    for (int j = i+1; j < size; j++)
    {
      if (array[min] > array[j])
      {
        min = j;
      }
    }
    int temp=array[i];
    array[i] = array[min];
    array[min]=temp;
  }
  cout << "\nSelection Sorted Array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}