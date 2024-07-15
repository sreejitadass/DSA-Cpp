#include<iostream>
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

class BSTiterator
{
stack<Node*>s;
bool reverse = false;
public:
    BSTiterator(Node* root, bool Isreverse)
    {
        reverse = Isreverse;
        pushAll(root);
    }

    bool hasNext()
    {
        return s.empty() ? false : true;
    }

    int next()
    {
        Node* nextNode = s.top();
        s.pop();
        if(!reverse)
            pushAll(nextNode->right);
        else
            pushAll(nextNode->left);
        return nextNode->val;
    }

    void pushAll(Node* root)
    {
        while(root!=nullptr)
        {
            s.push(root);
            if(!reverse)
                root=root->left;    //for next()--ascending inorder
            else
                root=root->right;   //for before()--descending inorder
        }
    }
};

bool findTarget(Node* root, int k)
{
    if(root==nullptr)
        return false;
    
    BSTiterator l(root, false);
    BSTiterator r(root, true);

    if (!l.hasNext() || !r.hasNext()) return false;

    int i = l.next();
    int j = r.next();
    while(i<j)
    {
        if(i+j == k)
            return true;
        else if(i+j > k)
            j = r.next();   //reduce j
        else
            i = l.next();   //increase i
    }
    return false;
}

int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    int k = 35;
    if(findTarget(root, k))
        cout<<"Exists"<<endl;
    else
        cout<<"Does not exist"<<endl;
    return 0;
}