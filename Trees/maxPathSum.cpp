#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

int solve(Node* root, int &maxSum)
{
    if(!root)
        return 0;

    int leftSum=max(0,solve(root->left,maxSum));
    int rightSum=max(0,solve(root->right,maxSum));
    maxSum = max(maxSum, root->val+leftSum+rightSum);

    return root->val+max(leftSum,rightSum);
}

int maxPathSum(Node* root)
{
    int maxSum = INT_MIN;
    solve(root,maxSum);
    return maxSum;
}

int main()
{
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);

    cout<<"Maximum path sum is: "<<maxPathSum(root)<<endl;
    return 0;
}