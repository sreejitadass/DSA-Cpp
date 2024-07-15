#include<iostream>
#include<queue>
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

void inorder(TreeNode* root, queue<TreeNode*>q)
{
    if(root!=nullptr)
    {
        inorder(root->right,q);
        q.push(root);
        inorder(root->left,q);
    }
}

TreeNode* increasingBST(TreeNode* root) 
{
    queue<TreeNode*>q;
    inorder(root, q);
    TreeNode* newRoot = q.front();
    TreeNode* node = newRoot;
    q.pop();

    while(!q.empty())
    {
        node->left = nullptr;
        node->right = q.front();
        node = node ->right;
        q.pop();
    }
    return newRoot;
}