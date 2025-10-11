#include <iostream>
#include <string>
using namespace std;

struct Node
{
  string url;
  Node *next;
};

Node *top = NULL;

void push(string site)
{
  Node *temp = new Node();
  temp->url = site;
  temp->next = top;
  top = temp;
}

void pop()
{
  if (top == NULL)
    cout << "No history." << endl;
  else
  {
    cout << "Going back from: " << top->url << endl;
    Node *temp = top;
    top = top->next;
    delete temp;
  }
}

void peek()
{
  if (top == NULL)
    cout << "History is empty." << endl;
  else
    cout << "Current page: " << top->url << endl;
}

void display()
{
  if (top == NULL)
    cout << "No browsing history." << endl;
  else
  {
    cout << "Browser history: ";
    Node *temp = top;
    while (temp != NULL)
    {
      cout << temp->url << " ";
      temp = temp->next;
    }
    cout << endl;
  }
}

int main()
{
  push("google.com");
  push("youtube.com");
  push("github.com");

  peek();
  display();

  pop();
  peek();
  display();

  while (top != nullptr)
  {
    Node* temp=top;
    top=top->next;
    delete temp;
  }
  return 0;
}
