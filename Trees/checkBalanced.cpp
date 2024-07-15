#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int findHeight(Node* root)
{
    if(root==nullptr)
        return 0;
    int lh=findHeight(root->left);
    int rh=findHeight(root->right);
    return 1+max(lh,rh);
}

//Brute-Force(n^2)
bool checkIfBalanced(Node* root)
{
    if(root==nullptr)
        return true;
    int lh=findHeight(root->left);
    int rh=findHeight(root->right);
    if(abs(lh-rh)>1)
        return false;
    bool l = checkIfBalanced(root->left);
    bool r = checkIfBalanced(root->right);
    if(!l || !r)
        return false;
    return true;
}

//Optimized(n)
int checkIfBalanced_opt(Node* root)
{
    if(root==nullptr)
        return 0;
    int lh=checkIfBalanced_opt(root->left);
    int rh=checkIfBalanced_opt(root->right);
    if(lh==-1 || rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return 1+max(lh,rh);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    //root->right->left->left=new Node(5);
    
    if(checkIfBalanced_opt(root)==-1)
        cout<<"Not balanced"<<endl;
    else
        cout<<"Balanced"<<endl;
    return 0;
}