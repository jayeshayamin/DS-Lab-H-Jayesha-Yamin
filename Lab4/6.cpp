#include <iostream>
using namespace std;

/*Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process.*/
int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  int *array = new int[size];
  cout << "Enter values: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }

  int gap = size;
  const float shrink = 1.3;
  int swapcount = 0, comparisoncount = 0;
  bool swapped = false;

  while (gap > 1 || swapped)
  {
    gap = int(gap / shrink);
    if (gap < 1)
      gap =1;
    swapped = false;

    for (int i = 0; i + gap < size; i++)
    {

      if (array[i] > array[i + gap])
      {
        int temp = array[i];
        array[i] = array[i + gap];
        array[i + gap] = temp;
        swapped = true;
        swapcount++;
      }
      comparisoncount++;
    }
  }
  cout << "\nComb Sorted Array: ";
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout<<"\nSwap Count: "<<swapcount;
  cout<<"\nComparison Count: "<<comparisoncount;
  delete[] array;
  return 0;
}