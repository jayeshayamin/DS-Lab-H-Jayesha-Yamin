#include <iostream>
using namespace std;

void printnumbers(int n)
{
    if(n==1)
    {cout<<1;
    return;}
    cout<<n<<endl;
    printnumbers(n-1);
}
void functionB(int n);
void functionA(int n)
{
    if(n==0 || n==1)
    {
        cout<<n<<" ";
        return;
    }
    functionB(n-1);
    cout<<n<<" ";
}
void functionB(int n)
{
    if(n==1||n==0)
    {
        cout<<n<<" ";
        return;
    }
    functionA( n-1);
    cout<<n<<" ";
}
int main() {
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Print Numbers: \n";
    printnumbers(n);
    cout<<"\nFunction A: ";
    functionA(n);
    return 0;
}
