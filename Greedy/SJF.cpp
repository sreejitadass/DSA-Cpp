#include<iostream>
#include<vector>
using namespace std;

int findAvgWaitTime(vector<int> &bt){
    sort(bt.begin(), bt.end());
    int n = bt.size();

    int waitTime = 0, totalWaitTime = 0;
    for(int i = 0;i<n;i++){
        totalWaitTime+= waitTime;
        waitTime+= bt[i];
    }
    return (totalWaitTime/n);
}

int main(){
    vector<int>bt = {3,1,4,2,5};
    cout<<"Average wait time: "<<findAvgWaitTime(bt)<<endl;
    return 0;
}