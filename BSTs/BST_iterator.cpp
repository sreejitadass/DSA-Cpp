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
public:
    BSTiterator(Node* root)
    {
        pushAll(root);
    }

    string hasNext()
    {
        return s.empty() ? "false" : "true";
    }

    int next()
    {
        Node* nextNode = s.top();
        s.pop();
        pushAll(nextNode->right);
        return nextNode->val;
    }

    void pushAll(Node* root)
    {
        while(root!=nullptr)
        {
            s.push(root); 
            root=root->left;    
        }
    }
};

int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTiterator itr(root);
    cout<<itr.next()<<endl;
    cout<<itr.next()<<endl;
    cout<<itr.hasNext()<<endl;
    cout<<itr.next()<<endl;
    cout<<itr.next()<<endl;
    cout<<itr.hasNext()<<endl;
    cout<<itr.next()<<endl;

    return 0;
}