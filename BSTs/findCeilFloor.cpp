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

Node* findCeil(Node* root, int x)
{
    Node* ceil = nullptr;
    while(root!=nullptr)
    {
        if(root->val == x)
        {
            ceil = root;
        }
        else if(root->val > x)
        {
            ceil = root;
            //look for smaller possible node > x
            root = root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return ceil;
}

Node* findFloor(Node* root, int x)
{
    Node* floor = nullptr;
    while(root!=nullptr)
    {
        if(root->val == x)
        {
            floor = root;
        }
        else if(root->val < x)
        {
            floor = root;
            //look for larger possible node < x
            root = root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return floor;
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

    int x = 7;
    Node* ceilValue = findCeil(root, x);
    Node* floorValue = findFloor(root, x);
    cout<<"Ceil value of "<<x<<": "<<ceilValue->val<<endl;
    cout<<"Floor value of "<<x<<": "<<floorValue->val<<endl;

    return 0;
}