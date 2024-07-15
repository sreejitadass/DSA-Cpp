#include <bits/stdc++.h>
using namespace std;

int findLongestSubarray(string s)
{
    vector<int> hash(256, -1); //(hash[character]=index)
    int l = 0, r = 0, maxLen = 0, len = 0, n = s.size();
    if (n == 0)
        return 0;
    while (r < n)
    {
        if (hash[s[r]] != -1) // found before
        {
            if (hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1; // update l
                break;
            }
        }
        else // not found before
        {
            hash[s[r]] = r;
            len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }
    }
    return maxLen;
}

int main()
{
    string s = "pwwkew";
    cout << "Maximum length: " << findLongestSubarray(s) << endl;
    return 0;
}