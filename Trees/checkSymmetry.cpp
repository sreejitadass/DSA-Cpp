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

bool isSymmetric(Node* root1, Node* root2)
{
    if(root1==nullptr || root2==nullptr)
        return root1==root2;
    return (root1->val==root2->val)&&isSymmetric(root1->left,root2->right)&&isSymmetric(root1->right,root2->left);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(3);
    root->right->right=new Node(4);

    if(isSymmetric(root->left,root->right))
        cout<<"Symmetric"<<endl;
    else
        cout<<"Not symmetric"<<endl;
    return 0;
}