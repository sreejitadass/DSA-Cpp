#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int val)
    {
        data = val;
        next = NULL;
        back = NULL;
    }
};

Node *findTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

vector<vector<int>> findSumPairs(Node *head, int target)
{
    Node *left = head, *right = findTail(head);
    vector<vector<int>> ans;
    while (left->data < right->data)
    {
        vector<int> pair;
        int sum = left->data + right->data;
        if (sum < target)
            left = left->next;
        else if (sum > target)
            right = right->back;
        else
        {
            pair = {left->data, right->data};
            ans.push_back(pair);
            left = left->next;
            right = right->back;
        }
    }
    return ans;
}

Node *convertArr2LL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 9};
    Node *head = convertArr2LL(arr);
    vector<vector<int>> ans = findSumPairs(head, 5);
    cout << "Pairs:  " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}