#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

pair<int, int> targetSum(vector<int> &nums, int target) {
    unordered_map<int, int> num_map; // To store the indices of the elements

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Using initializer list
        }
        num_map[nums[i]] = i;
    }
    return {-1, -1}; // Using initializer list
}

int main() {
    vector<int> nums = {1, 3, 4, 5, 7, 9};
    pair<int, int> result = targetSum(nums, 11);
    cout << "Index positions: " << result.first << ", " << result.second << endl;
    return 0;
}
