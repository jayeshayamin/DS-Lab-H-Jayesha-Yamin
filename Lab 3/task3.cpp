#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

int main()
{
  int size, input;
  cout << "Enter size of linked list: ";
  cin >> size;

  Node *head = nullptr;
  Node *tail = nullptr;
  for (int i = 0; i < size; i++)
  {
    cout << "Enter data: ";
    cin >> input;
    Node *newnode = new Node();
    newnode->data = input;
    newnode->next = nullptr;
    if (head == nullptr)
    {
      head = newnode;
      tail = newnode;
    }
    else
    {
      tail->next = newnode;
      tail = newnode;
    }
  }
  Node *temp = head;
  int k;
  cout << "Enter number to group by: ";
  cin >> k;
  int *array = new int[k];
  while (temp != nullptr)
  {
    int count = 0;
    while (temp != nullptr && count < k)
    {
      array[count] = temp->data;
      temp = temp->next;
      count++;
    }
    for (int j = count - 1; j >= 0; j--)
    {
      cout << array[j] << " ";
    }
  }
  delete[] array;
  return 0;
}