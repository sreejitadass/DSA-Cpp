#include <iostream>
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

int findHeight(Node* root, int &diameter)
{
    if(root==nullptr)
        return 0;
    int lh=findHeight(root->left,diameter);
    int rh=findHeight(root->right,diameter);
    diameter = max(diameter,(lh+rh));
    return 1+max(lh,rh);
}

//Brute-Force(n^2)
// int findDiameter(Node* root)
// {
//     if(root==nullptr)
//         return 0;
//     int lh=findHeight(root->left);
//     int rh=findHeight(root->right);
//     int current = lh+rh;

//     int l=findDiameter(root->left);
//     int r=findDiameter(root->right);
//     return max(current,(l+r));
// }

//Optimized(n)
int findDiameter_opt(Node* root)
{
    int diameter = 0;
    findHeight(root,diameter);
    return diameter;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->left->right->left = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);

    cout << "Diameter: " << findDiameter_opt(root) << endl;
    return 0;
}