#include<iostream>
#include<unordered_map>
using namespace std;

    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;

        for(int i = 0;i<s.size();i++)
        {
            mpp1[s[i]]++;
        }

        for(int i = 0;i<t.size();i++)
        {
            mpp2[t[i]]++;
        }

        for(int i = 0;i<s.size();i++){
            if(mpp1[s[i]]!=mpp2[t[i]])
                return false;
        }
        return true;
    }

int main()
{
    string s = "foo";
    string t = "bar";
    if(isIsomorphic(s,t))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}

