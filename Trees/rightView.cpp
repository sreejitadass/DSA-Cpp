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

//last node of every level
vector<int> rightView(Node* root)
{
    queue<Node*>q;
    q.push(root);
    vector<vector<int>>levelOrder;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++)
        {
            Node* node = q.front();
            q.pop();

            level.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        levelOrder.push_back(level);
    }
    vector<int>ans;
    for(auto &it: levelOrder)
    {
        int levelLength = it.size();
        ans.push_back(it[levelLength-1]);
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
    root->right->right = new Node(11);
    root->right->left = new Node(9);

    vector<int>ans=rightView(root);
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}