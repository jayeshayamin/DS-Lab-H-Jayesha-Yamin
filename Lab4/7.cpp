#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  int *bubble = new int[size];
  int *insertion = new int[size];
  int *shell = new int[size];

  cout << "Enter values: " << endl;
  for (int i = 0; i < size; i++)
  {
    int x;
    cin >> x;
    bubble[i] = x;
    insertion[i] = x;
    shell[i] = x;
  }

  // bubble sort
  int bcomp = 0, bswap = 0;
  clock_t bstart = clock();
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      bcomp++;
      if (bubble[j] > bubble[j + 1])
      {
        int temp = bubble[j];
        bubble[j] = bubble[j + 1];
        bubble[j + 1] = temp;
        bswap++;
      }
    }
  }
  clock_t bend = clock();

  // insertion sort
  int icomp = 0, iswap = 0;
  clock_t istart = clock();
  for (int i = 1; i < size; i++)
  {
    int key = insertion[i];
    int j = i - 1;
    while (j >= 0 && (icomp++, insertion[j] > key))
    {
      insertion[j + 1] = insertion[j];
      j--;
      iswap++;
    }
    insertion[j + 1] = key;
  }
  clock_t iend = clock();

  // shell sort
  int scomp = 0, sswap = 0;
  clock_t sstart = clock();
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; i++)
    {
      int temp = shell[i];
      int j = i;
      while (j >= gap && (scomp++, shell[j - gap] > temp))
      {
        shell[j] = shell[j - gap];
        j -= gap;
        sswap++;
      }
      shell[j] = temp;
    }
  }
  clock_t send = clock();

  cout << "\nBubble Sort: comparisons=" << bcomp << " swaps=" << bswap << " time=" << (double)(bend - bstart) / CLOCKS_PER_SEC << "s";
  cout << "\nInsertion Sort: comparisons=" << icomp << " swaps=" << iswap << " time=" << (double)(iend - istart) / CLOCKS_PER_SEC << "s";
  cout << "\nShell Sort: comparisons=" << scomp << " swaps=" << sswap << " time=" << (double)(send - sstart) / CLOCKS_PER_SEC << "s";

  delete[] bubble;
  delete[] insertion;
  delete[] shell;
  return 0;
}
