#include<iostream>
#include<vector>
using namespace std;

bool compareEnd(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals){
    int n = intervals.size();
    vector<vector<int>>mergedIntervals;
    sort(intervals.begin(), intervals.end(), compareEnd);

    vector<int> currentInterval = intervals[0];
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= currentInterval[1]) { // Overlapping
            currentInterval[1] = max(currentInterval[1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(currentInterval);
            currentInterval = intervals[i];
        }
    }
    mergedIntervals.push_back(currentInterval);

    return mergedIntervals;
}

int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>mergedIntervals = merge(intervals);
    for(auto it: mergedIntervals){
        for(int i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
