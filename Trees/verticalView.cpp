#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
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

vector<vector<int>> verticalTraversal(Node* root)
{
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});       //{node,{vertical,level}}
    //multiset allows ascending order + repition
    map<int,map<int,multiset<int>>>mpp;     //{vertical->level->{node,...}}
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node* node= it.first;
        int vertical= it.second.first;
        int level= it.second.second;

        mpp[vertical][level].insert(node->val);
        if(node->left)
            q.push({node->left,{vertical-1, level+1}});
        if(node->right)
            q.push({node->right,{vertical+1, level+1}});
    }

    //storing ans
    vector<vector<int>>ans;
    for(auto i: mpp)
    {
       vector<int>temp;
       for(auto j: i.second)
       {
            for(int val: j.second)
            {
                temp.push_back(val);
            }
       } 
       ans.push_back(temp);
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

    vector<vector<int>>ans = verticalTraversal(root);
    for(auto i:ans)
    {
        for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}