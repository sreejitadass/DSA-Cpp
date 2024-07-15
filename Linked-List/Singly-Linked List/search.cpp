#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool searchNode(Node *head, int target)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == target)
            return true;
        curr = curr->next;
    }
    return false;
}

Node *convertToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {12, 34, 56, 78, 90, 24, 89};
    Node *head = convertToLL(arr);

    if (searchNode(head, 56))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    return 0;
}