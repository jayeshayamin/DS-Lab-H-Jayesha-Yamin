#include <iostream>
using namespace std;

int sumtail(int n,int total)
{
    if(n==1)
    {
        return total+1;
    }
    return sumtail(n-1,total+n);
}
int sumNotail(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sumNotail(n-1);
}
int main() {
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"tail recursion: \n";
    cout<<sumtail(n,0);
cout<<"\nNon-tail recursion: \n";
    cout<<sumNotail(n);
    return 0;
}
/*In tail recursion the last action performed is the function calling itself whereas in non tail recursion the function performs more arithmetic or activity after the call. in stack non tail is basically a loop so it doesnt eat additional stack memory but in non tail the function requires memory to perform the remaining operations even after returning.*/
