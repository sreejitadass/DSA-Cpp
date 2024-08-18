#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

//to sort job in descending order of profit
bool comparison(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n){
    sort(arr, arr+n, comparison);

    int maxDeadline=arr[0].deadline;
    for(int i=0;i<n;i++){
        if(arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }

    vector<int>jobSlots(maxDeadline+1, -1);

    int maxProfit=0, maxJobCount=0;
    for(int i = 0;i<n;i++){
        if(jobSlots[arr[i].deadline]==-1){
            jobSlots[arr[i].deadline] = arr[i].id;
            maxProfit+= arr[i].profit;
            maxJobCount++;
        }
    }

    vector<int>ans = {maxJobCount, maxProfit};
    return ans;
}

int main(){
    Job arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    vector<int>ans = JobScheduling(arr, 4);
    cout<<"Required answer:  ";
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}