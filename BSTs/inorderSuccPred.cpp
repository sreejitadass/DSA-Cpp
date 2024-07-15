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

//for edge cases
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

//ceil value(not considering node itself)
int findInorderSuccessor(Node* root, Node* node)
{
    if(node==findMax(root))
        return -1;
    Node* succ = nullptr;
    while(root!=nullptr)
    {
        if(root->val > node->val)
        {
            succ = root;
            //look for smaller possible node > x
            root = root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return succ->val;
}

//floor value(not considering node itself)
int findInorderPredecessor(Node* root, Node* node)
{
    Node* pred = nullptr;
    if(node==root)
        return -1;
    while(root!=nullptr)
    {
        if(root->val < node->val)
        {
            pred = root;
            //look for greater possible node < x
            root = root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return pred->val;   
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

    Node* node = root->right->right;
    cout<<"The inorder successor of "<<node->val<<" = "<<findInorderSuccessor(root,node)<<endl;
    cout<<"The inorder predecessor of "<<node->val<<" = "<<findInorderPredecessor(root,node)<<endl;
    return 0;
}