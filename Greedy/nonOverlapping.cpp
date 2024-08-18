#include<iostream>
#include<vector>
using namespace std;

bool compareEnd(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    sort(intervals.begin(), intervals.end(), compareEnd);

    int nonOverlapping=1;
    int initialEnd = intervals[0][1];

    for(int i = 0;i<n;i++){
        int start = intervals[i][0];
        if(start>=initialEnd){
            initialEnd = intervals[i][1];
            nonOverlapping++;
        }
    }
    return n-nonOverlapping;
}

int main(){
    vector<vector<int>>intervals = {{1,100},{11,22},{1,11},{2,12}};
    cout<<"Removed intervals: "<<eraseOverlapIntervals(intervals)<<endl;
    return 0;
}