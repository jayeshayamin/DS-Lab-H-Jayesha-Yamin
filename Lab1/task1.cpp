#include <stdio.h>
#include <iostream>
using namespace std;

/*Q1. Suppose you are developing a bank account management system, and you have defined the BankAccount class with the required constructors. You need to demonstrate the use of these constructors in various scenarios. 1. Default Constructor Usage: Create a default-initialized BankAccount object named account1. Print out the balance of account1. 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with an initial balance of $1000. Print out the balance of account2. 3. Copy Constructor Usage: Using the account2 you created earlier, create a new BankAccount object named account3 using the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the balance of account2 to ensure it hasn't been affected by the transaction involving account3.
 */
class BankAccount
{
public:
  float* balance;

  BankAccount()
  {
    balance =new float(500);//starting balance default
  }

  BankAccount(float newbalance)
  {
    balance =new float(newbalance);
  }
  BankAccount(const BankAccount& newobject)
  {
    balance=new float(*newobject.balance);
  }
  ~BankAccount()
  {
    delete balance;
  }
  void print()
  {
    cout<<"Balance: $"<<*balance<<endl;
  }
};
int main()
{
  BankAccount account1;
  account1.print();
BankAccount account2(1000);
account2.print();
BankAccount account3(account2);
*account3.balance-=300;
account3.print();
account2.print();
}