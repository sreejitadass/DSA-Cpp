#include<iostream>
#include<unordered_map>
using namespace std;

/*
Find all substrings and for each substring, store a hashmap of frequency of all
characters and find the difference and max and min occuring frequencies and add it to
final ans for all substrings
*/

int beautySum(string s) {
    int n = s.size();
    int ans=0,diff;
    for(int i=0; i<n; i++){
        unordered_map<char,int>mpp;
        for(int j=i; j<n; j++){
            mpp[s[j]]++;

            int maxOccurs=INT_MIN, minOccurs=INT_MAX;
            for(auto it: mpp){
                maxOccurs = max(maxOccurs, it.second);
                minOccurs = min(minOccurs, it.second);
            }
            diff=maxOccurs-minOccurs;
            ans+=diff;
        }
    }  
    return ans; 
}

int main(){
    string s = "aabcbaa";
    cout<<"Total sum of beauty of all substrings: "<<beautySum(s)<<endl;
    return 0;
}