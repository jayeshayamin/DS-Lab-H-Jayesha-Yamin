#include <iostream>
using namespace std;

/*Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays.*/

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

  
  cout <<"Unsorted Array: "<<endl;
  for (int i = 0; i < size; i++)
  {
    cout<<array[i]<<" ";
  }

  for(int i=0;i<size-1;i++)
  {for(int j=0;j<size-i-1;j++)
    {
      if(array[j]>array[j+1])
      {
        int temp=array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
      }
    }
  }
  cout <<"\nBubbleSorted Array: "<<endl;
  for (int i = 0; i < size; i++)
  {
    cout<<array[i]<<" ";
  }
  delete[] array;
  return 0;
}