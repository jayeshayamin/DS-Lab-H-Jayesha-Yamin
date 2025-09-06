#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class DoubleNode
{
public:
  int data2;
  DoubleNode *prev;
  DoubleNode *next;
};

int main()
{
  int size;
  cout << "Enter size: ";
  cin >> size;

  Node *singlehead = nullptr;
  Node *singletail = nullptr;
  for (int i = 0; i < size; i++)
  {
    Node *temp = singlehead;
    Node *single = new Node();
    single->data = i + 1;
    single->next = nullptr;
    if (singlehead == nullptr)
    {
      singlehead = single;
      singletail = single;
    }
    else
    {
      singletail->next = single;
      singletail = single;
    }
  }

  Node *temp = singlehead;
  cout << "Singe Linked List:" << endl;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  temp = singlehead;
  DoubleNode *Doublehead = nullptr;
  DoubleNode *Doubletail = nullptr;
  while (temp != nullptr)
  {
    DoubleNode *Double = new DoubleNode();
    Double->data2 = temp->data;
    Double->prev = Doubletail;
    Double->next = nullptr;
    if (Doublehead == nullptr)
    {
      Doublehead = Double;
      Doubletail = Double;
    }
    else
    {
      Doubletail->next = Double;
    }
    Doubletail = Double;
    temp = temp->next;
  }
  cout << "\nDouble Linked List: " << endl;
  DoubleNode *dtemp = Doublehead;
  do
  {
    cout << dtemp->data2 << " ";
    dtemp = dtemp->next;
  } while (dtemp != nullptr);

  singletail->next = singlehead;
  cout << "\nCircular List: " << endl;
  temp = singlehead;
  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != singlehead);

  return 0;
}