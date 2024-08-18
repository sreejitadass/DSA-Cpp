#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMaxValueKnapsack(int N, int W, vector<int>& values, vector<int> &weights){
    vector<int>arr(N,0);        //value/weight ratio array
    for(int i = 0;i<N;i++){
        arr[i] = values[i]/weights[i];
    }
    sort(arr.begin(), arr.end());

    int currW = 0, totalValue = 0;
    for(int i = 0;i<N;i++){
        if(currW + weights[i] <= W){
            currW+= weights[i];
            totalValue+= values[i];
        }
        else{
            int remaining = W - currW;
            totalValue+= (values[i]/weights[i])*remaining;
        }
    }
    return totalValue;
}

int main(){
    int N = 3, W = 50;
    vector<int>values = {100,60,120};
    vector<int>weights = {20,10,30};
    cout<<"Maximum value in knapsack: "<<findMaxValueKnapsack(N,W,values,weights)<<endl;
    return 0;
}