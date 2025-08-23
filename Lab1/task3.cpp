#include <stdio.h>
#include <iostream>
using namespace std;

/*Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the Rule of Three by defining a destructor, copy constructor, and copy assignment operator. Demonstrate the behavior of both shallow and deep copy using test cases.*/

class Box
{
private:
  int *number;

public:
  Box()
  {
    number = new int(200);
  }
  Box(const Box &newbox)
  {
    number = new int(*newbox.number);
  }
  Box &operator=(const Box &newobject)
  {
    if (this != &newobject)
    {
      delete number;
      number = new int(*newobject.number);
    }
    return *this;
  }
  ~Box()
  {
    delete number;
  }
  void setvalue(int value) { *number = value; }
  int getvalue() const
  {
    cout << "Number: ";
    return *number;
  }
};
int main()
{
  Box b1;
  cout << b1.getvalue() << endl;
  Box b2(b1);
  cout << b2.getvalue() << endl;
  Box b3 = b2;
  cout << b3.getvalue() << endl;
}