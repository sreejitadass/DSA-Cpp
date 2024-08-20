#include<iostream>
using namespace std;

/* 
We are breaking a number to its prime factors: for eg: n=6 can be written as 6 = 2X3
so we can paste A 2 times followed by 3 times to get minsteps=2
*/

int minSteps(int n) {
    if(n==1)
        return 0; 
    int cntSteps=0;
    //starting with first prime factor=2
    int factor=2;
    while(n>1){
        //if the prime factor divides n, then we can paste it factor number of times
        while(n%factor==0){
            cntSteps+=factor;
            //decrease n by factor
            n/=factor;
        }
        //increase factor to next prime factor
        factor++;
    }
    return cntSteps;
}

int main(){
    cout<<"Minimum steps are: "<<minSteps(18)<<endl;
    return 0;
}
    