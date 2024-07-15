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

Node* findMax(Node* root)
{
    if(root==nullptr)
        return root;
    while(root->right!=nullptr)
    {
        root=root->right;
    }
    return root;
}

Node* findMin(Node* root)
{
    if(root==nullptr)
        return root;
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    Node* max = findMax(root);
    Node* min = findMin(root);
    cout<<"Maximum node: "<<max->val<<endl;
    cout<<"Minimum node: "<<min->val<<endl;
    return 0;
}