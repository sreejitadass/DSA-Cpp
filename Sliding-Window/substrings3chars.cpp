#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{
    int n = s.size(), r = 0, l = 0, count = 0;
    vector<int> hash(3, 0);
    while (r < n)
    {
        hash[s[r] - 'a']++; // a=0,b=1,c=2
        while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0)
        {
            count += (n - r);
            hash[s[l] - 'a']--;
            l++;
        }
        r++;
    }
    return count;
}

int main()
{
    string s = "abcabc";
    cout << "Total substrings: " << countSubstrings(s) << endl;
    return 0;
}