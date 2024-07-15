#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
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

vector<int>topView(Node*root)
{
    queue<pair<Node*,int>>q;
    q.push({root,0});
    map<int,int>mpp;

    while(!q.empty())
    {
        auto it=q.front();
        q.pop();

        Node* node=it.first;
        int vertical=it.second;

        //if vertical found more than once, dont push that node
        if(mpp.find(vertical)==mpp.end())
        {
            mpp[vertical]=node->val;
        }
        if(node->left)
            q.push({node->left,vertical-1});
        if(node->right)
            q.push({node->right,vertical+1});
    }
    vector<int>ans;
    for(auto it: mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int>ans=topView(root);
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}