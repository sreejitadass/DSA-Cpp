#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxSubstring(string s, int k)
{
    int n = s.size(), r = 0, l = 0, maxf = 0, maxlen = 0;
    vector<int> mpp(26, 0);
    while (r < n)
    {
        mpp[s[r] - 'a']++;
        maxf = max(maxf, mpp[s[r] - 'a']);
        while ((r - l + 1) - maxf > k)
        {
            mpp[s[l] - 'a']--;
            l++;
            for (int i = 0; i < 26; i++)
            {
                maxf = max(maxf, mpp[i]);
            }
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{
    string s = "AABABBA";
    int k = 2;
    cout << "Maximum length of substring with at most " << k << " changes: " << findMaxSubstring(s, k) << endl;
    return 0;
}
