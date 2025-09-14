#include <iostream>
using namespace std;

/*Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present. */

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
  for (int i = 1; i < size; i++)
  {
    int key = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > key)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  cout << "\nInsertion Sorted Array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  int n;
  cout << "\nEnter target value to find: ";
  cin >> n;
  bool flag = false;

  int low = 0, high = size - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (array[mid] == n)
    {
      cout << "n found at index: " << mid;
      flag = true;
      break;
    }
    else if (array[mid] < n)
      low = mid + 1;
    else
      high = mid - 1;
  }
  if (!flag)
  {
    cout << "Target not found!";
  }
  delete[] array;
  return 0;
}