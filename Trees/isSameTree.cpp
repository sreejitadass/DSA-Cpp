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

bool isSameTree(Node *p, Node *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;
    else if (p->data != q->data)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    Node *p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    p->left->left = new Node(4);
    p->left->right = new Node(5);
    p->right->left = new Node(6);
    p->right->right = new Node(7);
    p->left->right->left = new Node(8);
    p->right->right->left = new Node(9);
    p->right->right->right = new Node(10);

    Node *q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->left->left = new Node(4);
    q->left->right = new Node(5);
    q->right->left = new Node(6);
    q->right->right = new Node(99);
    q->left->right->left = new Node(8);
    q->right->right->left = new Node(9);
    q->right->right->right = new Node(10);

    if (isSameTree(p, q))
        cout << "Same tree" << endl;
    else
        cout << "Not same tree" << endl;
    return 0;
}