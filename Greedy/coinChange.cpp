#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMinCoins(vector<int> &coins, int value){
    sort(coins.begin(), coins.end());
    int n = coins.size(),count=0;

    for(int i = n-1; i>=0; i--){
        while(value >= coins[i]){
            value-=coins[i];
            count++;
        }
    }
    return count!=-1 ? count : -1;
}

int main(){
    vector<int>coins = {10,7};
    int value = 70;
    cout<<"Minimum coins required: "<<findMinCoins(coins, value)<<endl;
    return 0;
}