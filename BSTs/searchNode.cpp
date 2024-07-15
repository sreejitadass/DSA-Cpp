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

bool searchNode(Node* root, int target)
{
    while(root!=nullptr)
    {
        if(root->val==target)
            return true;
        //if target is smaller, go to left subtree
        else if(root->val > target)
            root=root->left;
        //if target is greater, go to right subtree
        else
            root=root->right;
    }
    return false;
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

    bool result = searchNode(root, 10);
    if(result)
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}