#include<iostream>
#include<vector>
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

void inorderTraversal(Node* root, vector<int>&ans)
{
    if(root!=nullptr)
    {
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
}

//Brute force
bool checkIfBST(Node* root)
{
    vector<int>ans;
    inorderTraversal(root, ans);

    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i]>=ans[i+1])
            return false;
    }
    return true;
}

//Optimal - using recursion
bool checkIfBST_optimal(Node* root, int minVal, int maxVal)
{
    if (root == nullptr)
        return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return checkIfBST_optimal(root->left, minVal, root->val) &&
           checkIfBST_optimal(root->right, root->val, maxVal);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    if (checkIfBST_optimal(root, -1e9, 1e9))
        cout << "BST" << endl;
    else
        cout << "BT" << endl;
    return 0;
}