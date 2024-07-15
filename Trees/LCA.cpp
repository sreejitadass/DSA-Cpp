#include<iostream>
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

TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr || root == p || root == q)
        return root;
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p,q);
    if(left == nullptr)
        return right;
    else if(right == nullptr)
        return left;
    else
        return root;
}