#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char,int>mpp;
    mpp['I']=1;
    mpp['V']=5;
    mpp['X']=10;
    mpp['L']=50;
    mpp['C']=100;
    mpp['D']=500;
    mpp['M']=1000;

    int num=0;
    for(int i=0; i<s.size();i++){
        if((s[i]=='I' && s[i+1]=='V') || (s[i]=='I' && s[i+1]=='X') 
            || (s[i]=='X' && s[i+1]=='L') || (s[i]=='X' && s[i+1]=='C') 
            || (s[i]=='C' && s[i+1]=='D') || (s[i]=='C' && s[i+1]=='M')){
                num+=(mpp[s[i+1]]-mpp[s[i]]);
                i++;
        }
        else{
            num+=mpp[s[i]];
        }
    }
    return num;
}

int main(){
    string s = "XXIV";
    cout<<"Integer: "<<romanToInt(s)<<endl;
    return 0;
}