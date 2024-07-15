#include<iostream>
using namespace std;

double calcPower(double x, int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return x * calcPower(x,n-1);
    else
        return 1.00/(x*calcPower(x,abs(n)-1));
}


int main()
{
    double x=2.100;
    int n=-3;
    cout<<x<<" raised to the power of "<<n<<": "<<calcPower(x,n)<<endl;
    return 0;
}