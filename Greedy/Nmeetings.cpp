#include<iostream>
#include<vector>
using namespace std;

struct meetings{
    int pos;
    int startTime;
    int endTime;
};

bool comparison(meetings a, meetings b){
    return a.endTime < b.endTime;
}

vector<int>findMeetingsSequence(int N, vector<int> &start, vector<int> &end){
    struct meetings m[N];
    for(int i = 0;i<N;i++){
        m[i].pos = i+1;
        m[i].startTime = start[i];
        m[i].endTime = end[i];
    }

    sort(m, m+N, comparison);

    vector<int>sequenceMeetings;
    sequenceMeetings.push_back(m[0].pos);
    int initialEnd = m[0].endTime;

    for(int i = 1;i<N;i++){
        if(m[i].startTime >= initialEnd){
            initialEnd = m[i].endTime;
            sequenceMeetings.push_back(m[i].pos);
        }
    }
    return sequenceMeetings;
}

int main(){
    int N = 47;
    vector<int> start = {86, 32, 31, 98, 37, 65, 98, 71, 99, 58, 59, 32, 52, 69, 15, 75, 4, 86, 57, 36, 83, 18, 58, 50, 43, 29, 98, 53, 80, 5, 89, 73, 8, 97, 17, 100, 9, 21, 55, 55, 32, 74, 60, 32, 87, 72, 54};
    vector<int> end = {126, 112, 134, 138, 89, 118, 107, 124, 126, 83, 133, 64, 124, 109, 108, 132, 111, 95, 82, 106, 86, 118, 82, 78, 92, 55, 128, 121, 118, 95, 94, 110, 111, 146, 124, 148, 95, 146, 109, 61, 93, 126, 74, 76, 110, 78, 91};
    
    vector<int>ans = findMeetingsSequence(N,start,end);
    cout<<"Required answer:  ";
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}