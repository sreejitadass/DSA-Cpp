#include <iostream>
#include <vector>
using namespace std;

//[1,2,4,1,2]-->(1^1)^(2^2)^4=0^0^4=4,performing XOR on all elts as num^num=0

int findSingleNumber(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
        res ^= nums[i];
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 4, 1, 2};
    int res = findSingleNumber(nums);
    cout << "Single number: " << res << endl;

    return 0;
}