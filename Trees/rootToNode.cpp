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

bool solve(Node* root, int node, vector<int>&ans)
{
    if(root==nullptr)
        return false;

    ans.push_back(root->val);
    if(root->val == node)
        return true;
    if(solve(root->left,node,ans)||solve(root->right,node,ans))
        return true;

    ans.pop_back();
    return false;
}

int main()
{
    vector<int>ans;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(11);
    root->right->left = new Node(9);
    int node = 6;
    solve(root,node,ans);

    cout<<"Path: ";
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}