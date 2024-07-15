#include<iostream>
#include<vector>
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

void inorderTraversal(TreeNode* root, TreeNode* &prev, int &minDiff)
{
    if(root==nullptr)
        return;
    inorderTraversal(root->left, prev, minDiff);
    if(prev!=nullptr)
    {
        minDiff = min(minDiff, root->val-prev->val);
    }
    prev = root;
    inorderTraversal(root->right, prev, minDiff);   
}

int findMinDiff(TreeNode* root)
{
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    inorderTraversal(root, prev, minDiff);
    return minDiff;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    cout<<"Minimum difference: "<<findMinDiff(root)<<endl;
    return 0;
}