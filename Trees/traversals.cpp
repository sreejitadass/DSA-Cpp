#include <iostream>
#include<vector>
#include<queue>
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

void preorder(Node *root, vector<int> &ans)
{
    if (root != nullptr)
    {
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
}

void inorder(Node *root, vector<int> &ans)
{
    if (root != nullptr)
    {
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
}

void postorder(Node *root, vector<int> &ans)
{
    if (root != nullptr)
    {
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->data);
    }
}

void levelorder(Node *root, vector<int> &ans)
{
    if (root != NULL)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            for (int i = 0; i < q.size(); i++)
            {
                Node *n = q.front();
                q.pop();
                ans.push_back(n->data);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }
    }
}

vector<vector<int>> findTraversals(Node *root)
{
    vector<int> pre, in, post, level;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    levelorder(root, level);

    return {pre, in, post, level};
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<vector<int>> traversals = findTraversals(root);

    cout << "\nPreorder:  ";
    for (int j = 0; j < traversals[0].size(); j++)
    {
        cout << traversals[0][j] << " ";
    }
    cout << endl;

    cout << "Inorder:  ";
    for (int j = 0; j < traversals[1].size(); j++)
    {
        cout << traversals[1][j] << " ";
    }
    cout << endl;

    cout << "Postorder:  ";

    for (int j = 0; j < traversals[2].size(); j++)
    {
        cout << traversals[2][j] << " ";
    }
    cout << endl;

    cout << "Levelorder:  ";

    for (int j = 0; j < traversals[3].size(); j++)
    {
        cout << traversals[3][j] << " ";
    }
    cout << endl;

    return 0;
}