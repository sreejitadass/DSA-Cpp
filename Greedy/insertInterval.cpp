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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int newStart = newInterval[0];

        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        bool inserted=false;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > newStart && !inserted) {
                inserted=true;
                intervals.insert(intervals.begin() + i, newInterval);
            }
        }

        if(!inserted){
            intervals.push_back(newInterval);
        }

        vector<vector<int>> insertedIntervals = merge(intervals);
        return insertedIntervals;
}

int main(){
    vector<vector<int>>intervals={{1,3},{6,9}};
    vector<int>newInterval={2,5};
    vector<vector<int>>ans = insert(intervals,newInterval);

    for(auto i: ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}