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
    if(root == nullptr)
        return root;
    int current = root->val;
    if(current < p->val && current < q->val)
        return findLCA(root->right, p, q);
    if(current > p->val && current > q->val)
        return findLCA(root->left, p, q);
    return root;
}