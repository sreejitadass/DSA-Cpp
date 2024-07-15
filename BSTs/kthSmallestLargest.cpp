#include<iostream>
#include<vector>
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

void inorderTraversal(Node* root, vector<int>&ans)
{
    if(root!=nullptr)
    {
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
}

//Brute
pair<int,int> findKthSmallestLargest(Node* root, int k)
{
    vector<int> ans;
    inorderTraversal(root, ans);

    pair<int,int>res;   //{small, large}
    int n =ans.size();
    res.first = ans[k-1];
    res.second = ans[n-k];
    return res;
}

//For kth smallest in left subtree
void inorder_opt(Node* root, int &cnt, int k, int &kthSmallest)
{
    if(root==nullptr || cnt>k)
        return;
    inorder_opt(root->left, cnt, k, kthSmallest);
    cnt++;
    if(cnt==k)
    {
        kthSmallest = root->val;
        return;
    }
    inorder_opt(root->right, cnt, k, kthSmallest);
}

//For kth largest in right subtree
void reverse_inorder_opt(Node* root, int &cnt, int k, int &kthLargest)
{
    if(root==nullptr || cnt>k)
        return;
    reverse_inorder_opt(root->right, cnt, k, kthLargest);
    cnt++;
    if(cnt==k)
    {
        kthLargest = root->val;
        return;
    }
    reverse_inorder_opt(root->left, cnt, k, kthLargest);
}

//Optimal
pair<int,int> findKthSmallestLargest_opt(Node* root, int k)
{
    int cnt = 0;
    int kthSmallest, kthLargest;
    inorder_opt(root, cnt, k, kthSmallest);

    cnt = 0;
    reverse_inorder_opt(root, cnt, k, kthLargest);
    return {kthSmallest, kthLargest};
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    int k = 3;
    pair<int,int>res = findKthSmallestLargest_opt(root, k);
    cout<<k<<" smallest element: "<<res.first<<endl;
    cout<<k<<" largest element: "<<res.second<<endl;
    return 0;
}
