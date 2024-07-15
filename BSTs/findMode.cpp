#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

void inorder(TreeNode* root, unordered_map<int,int>&freq)
{
    if(!root)
        return;
    inorder(root->left, freq);
    freq[root->val]++;
    inorder(root->right, freq);
}

vector<int> findMode(TreeNode* root)
{
    if(root==nullptr)
        return {};
    vector<int>ans;
    unordered_map<int,int>freq;     //{node, frequency}
    inorder(root, freq);

    int maxFreq=INT_MIN;
    for(auto &it: freq)
    {
        if(it.second>maxFreq)
            maxFreq = it.second;
    }

    for(auto &it: freq)
    {
        if(it.second == maxFreq)
            ans.push_back(it.first);
    }
    return ans;
}