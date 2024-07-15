#include<iostream>
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

vector<vector<int>> zigzagLevelOrder(Node* root)
{
    vector<vector<int>>ans;
    if(root==nullptr)
        return ans;
    queue<Node *>q;
    q.push(root);
    bool LtoR = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++)
        {
            Node* n=q.front();
            q.pop();

            int index = LtoR?i:(size-i-1);
            temp[index]=n->data;

            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        LtoR = !LtoR;
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>>ans = zigzagLevelOrder(root);
    cout<<"Zigzag traversal: ";
    for(auto it: ans)
    {
        for(int i:it)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}