#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> s;
    //push and pop till k>0
    for (int i = 0; i < num.size(); i++)
    {
        while (!s.empty() && k > 0 && s.top()-'0' > num[i]-'0')
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    //for 123456 test cases
    while (k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }

    //if all are removed - k==n
    if (s.empty())
        return "0";

    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    // Remove leading zeros + all zeroes case
    while (!ans.empty() && ans[0] == '0')
    {
        ans.erase(ans.begin());
    }
    return ans.empty() ? "0" : ans;
}

int main()
{
    string num = "100";
    int k = 1;
    cout << "Smallest number: " << removeKdigits(num, k) << endl;
    return 0;
}
