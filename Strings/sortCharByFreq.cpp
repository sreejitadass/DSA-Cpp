#include<iostream>
#include<unordered_map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

void findCharFrequency(string s, unordered_map<char,int> &freq){
    for(int i=0; i<s.size(); i++){
        freq[s[i]]++;
    }
}

string frequencySort(string s) {
    unordered_map<char,int>freq;
    string ans = "";

    findCharFrequency(s,freq);
    
    //copying map to vector of pairs
    vector<pair<char,int>>freqVec(freq.begin(),freq.end());

    //descending comparator sort
    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    //find ans
    for(auto &pair: freqVec){
        int frequency = pair.second;
        char letter = pair.first;

        while(frequency>0){
            ans+=letter;
            frequency--;
        }
    }
    
    return ans;
}

int main()
{
    string s = "Aabb";
    cout<<"String: "<<frequencySort(s)<<endl;
    return 0;
}