#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

Node* Listmake(Node* head,int size)
{
  int input;
  for (int i = 0; i < size; i++)
  {
    cout << "Enter list input: " << endl;
    cin >> input;
    Node *list = new Node();
    list->data = input;
    list->next=nullptr;
    if (head == nullptr)
    {
      head = list;
    }
    else
    {
      Node *temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = list;
    }
  }
  return head;
}
int main()
{
  Node *head1 = nullptr;
  Node *head2 = nullptr;
  int size;
  cout << "Enter size of list: ";
  cin >> size;
  head1=Listmake(head1,size);
  head2=Listmake(head2,size);


  Node* a=head1;
  Node* b=head2;

  Node* head=nullptr;
  Node* tail=nullptr;
  if(a->data<b->data)
  {
    head=a;
    a=a->next;
  }
  else
  {
    head=b;
    b=b->next;
  }

  tail=head;

  while(a!=nullptr && b!=nullptr)
  {
  if (a->data < b->data) {
      tail->next = a;
      a = a->next;
  } else {
      tail->next = b;
      b = b->next;
  }
  tail = tail->next;
}
  if(a)
  {
    tail->next=a;
  }
  if(b)
  {
    tail->next=b;
  }
Node* temp=head;
  cout<<"Printing Merged List: "<<endl;
  while(temp->next!=nullptr)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
    cout<<temp->data<<" ";
  return 0;
}