#include <iostream>
using namespace std;

int calculatefactorial(int n)
{
    if(n==1 || n==0)
    return 1;
    return n*calculatefactorial(n-1);
}
int main() {
    int n;
    cout<<"Enter factorial: ";
    cin>>n;
    cout<<"Calculated facotiral: "<<calculatefactorial(n);
    return 0;
}
