#include<iostream>
#include<vector>
#include<stack>
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

//to check whether its a leaf node
bool isLeaf(Node*root)
{
    return (root->left==nullptr)&&(root->right==nullptr);
}

//left boundary excluding the leaves
void addLeftBoundary(Node*root, vector<int>&ans)
{
    Node*curr=root->left;
    while(curr!=nullptr)
    {
        if(!isLeaf(curr))
            ans.push_back(curr->val);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

//add the leaves
void addLeaves(Node* root, vector<int>&ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->val);
        return;
    }
    if(root->left)
        addLeaves(root->left,ans);
    if(root->right)
        addLeaves(root->right,ans);
}

//add right boundary in reverse direction
void addRightBoundary(Node*root, vector<int>&ans)
{
    stack<int>s;
    Node*curr=root->right;
    while(curr!=nullptr)
    {
        if(!isLeaf(curr))
            s.push(curr->val);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int>ans;
    ans.push_back(root->val);
    addLeftBoundary(root, ans);
    addLeaves(root,ans);
    addRightBoundary(root, ans);
    cout<<"Boundary traversal: ";
    for(int i:ans)
        cout<<i<<" ";
    return 0;
}