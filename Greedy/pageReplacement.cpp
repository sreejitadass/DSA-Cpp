#include<iostream>
#include<deque>
#include<vector>
using namespace std;

bool isInQueue(deque<int> &d, int element) {
    return find(d.begin(), d.end(), element) != d.end();
}

int pageFaults(int N, int C, vector<int> &pages){
    deque<int> d;
    int pgFaults = 0;

    for(int i = 0; i < N; i++) {
        int currentPage = pages[i];

        if(!isInQueue(d, currentPage)) {
            if(d.size() == C) {
                d.pop_front();
            }
            d.push_back(currentPage);
            pgFaults++; 
        } else {
            d.erase(find(d.begin(), d.end(), currentPage)); 
            d.push_back(currentPage);
        }
    }
    return pgFaults;
}

int main(){
    int N=9,C=4;
    vector<int>pages = {5,0,1,3,2,4,1,0,5};
    cout<<"Total page faults: "<<pageFaults(N,C,pages);
}
