#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/* Create a C++ class named "Exam" using DMA designed to manage student exam records, complete with a shallow copy implementation? Define attributes such as student name, exam date, and score within the class, and include methods to set these attributes and display exam details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues?
 */

class Exam
{
private:
  char *name;
  int *date;
  float *score;

public:
  Exam(const char *n, int d, float s)
  {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    date = new int(d);
    score = new float(s);
    cout << "Information Recorded." << endl;
  }
  void display()
  {
    cout << "Exam Details: " << endl;
    cout << "Student Name: " << name << "| Date: " << *date << "| Score: " << *score << endl;
  }
  ~Exam()
  {
    delete[] name;
    delete date;
    delete score;
  }
};
int main()
{
  Exam e1("Jayesha", 23, 75);
  e1.display();

  Exam e2(e1);
  e2.display();
}