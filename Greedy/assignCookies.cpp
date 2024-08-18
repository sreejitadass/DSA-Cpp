#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size(), m = s.size();

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int l = 0, r = 0;
    while(r<m && l<n){
        //greed satisfied then move child and size
        if(s[r]>=g[l]){
            l++;
            r++;
        }
        //not satisfied - move only size
        else{
            r++;
        }
    }
    return l;
}

int main()
{
    vector<int>g={1,5,3,3,4};
    vector<int>s={4,2,1,2,1,3};
    cout<<findContentChildren(g,s)<<endl;
    return 0;
}