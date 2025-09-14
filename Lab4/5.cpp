#include <iostream>
using namespace std;

int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  int *array = new int[size];
  cout << "Enter sorted values: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }

  int key;
  cout << "Enter target value: ";
  cin >> key;
  bool flag = false;
  int low = 0, high = size - 1;
  while (low <= high && key >= array[low] && key <= array[high])
  {
    int pos = low + ((key - array[low]) / (array[high] - array[low])) * (high - low);
    if (array[pos] == key)
    {
      cout << key << " found at index: " << pos;
      flag = true;
      break;
    }
    if (key > array[pos])
      low = pos + 1;
    else
      high = pos - 1;
  }
  if(!flag)
  {
    cout<<"Element not found.";
  }
  delete[] array;
  return 0;
}