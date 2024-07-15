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

Node* insertNode(Node* root, int data)
{
    Node* newnode = new Node(data);
    if(root==nullptr)
    {
        return newnode;
    }
    Node* curr = root;
    while(curr!=nullptr)
    {
        if(curr->val < data)
        {
            if(curr->right!=nullptr)
                curr=curr->right;
            else
            {
                curr->right = newnode;
                break;
            }
        }
        else
        {
            if(curr->left!=nullptr)
                curr=curr->left;
            else
            {
                curr->left = newnode;
                break;
            }   
        }
    }
    return root;
}

void printInorder(Node* root)
{
    if(root==nullptr)
        return;
    else
    {
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
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
    int data = 9;

    cout<<"Original tree: ";
    printInorder(root);

    root = insertNode(root,data);
    cout<<"\nAfter insertion: ";
    printInorder(root);

    return 0;
}