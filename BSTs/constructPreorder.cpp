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

Node* BSTfromPreorder(vector<int>&preorder)
{
    
}

void printInorder(Node* root)
{
    if(root==nullptr)
        return;
    printInorder(root->left);
    cout<<root->val;
    printInorder(root->right);
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    Node* root = BSTfromPreorder(preorder);
    printInorder(root);

    return 0;
}