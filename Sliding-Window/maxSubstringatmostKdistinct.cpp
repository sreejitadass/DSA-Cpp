#include <bits/stdc++.h>
using namespace std;

int findMaxSubstring(string s, int k)
{
    int n = s.size(), r = 0, l = 0, maxlen = 0, len = 0;
    unordered_map<char, int> mpp;
    if (k > n)
        return 0;
    while (r < n)
    {
        mpp[s[r]]++;
        if (mpp.size() > k)
        {
            // shrink window
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);
        r++;
    }
    return maxlen;
}

int main()
{
    string s = "abcdabcd";
    cout << "Maximum length: " << findMaxSubstring(s, 4) << endl;
    return 0;
}