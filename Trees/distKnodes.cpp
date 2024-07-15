#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

//to traverse upwards in parent direction
void buildParentMap(Node* root, unordered_map<Node*, Node*>& parentMap) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left) {
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
}

//to traverse for left+right children
vector<int> findNodesAtDistanceK(Node* root, Node* target, int k)
{
    if (!root) return {};

    unordered_map<Node*, Node*> parentMap;
    buildParentMap(root, parentMap);

    queue<Node*> q;
    q.push(target);
    unordered_map<Node*, int> vis;
    vis[target] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int size = q.size();
        if (cnt == k) break;
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            /*Check in 3 directions - down left, down right and up parent*/

            //DOWN LEFT
            if (node->left && !vis[node->left]) {
                q.push(node->left);
                vis[node->left] = 1;
            }

            //DOWN RIGHT
            if (node->right && !vis[node->right]) {
                q.push(node->right);
                vis[node->right] = 1;
            }

            //UP PARENT
            if (parentMap[node] && !vis[parentMap[node]]) {
                q.push(parentMap[node]);
                vis[parentMap[node]] = 1;
            }
        }
        cnt++;
    }
    vector<int> ans;
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node* target = root->left;
    int k = 2;
    vector<int>ans = findNodesAtDistanceK(root, target, k);
    for(int i: ans)
        cout<<i<<" ";
    return 0;
}