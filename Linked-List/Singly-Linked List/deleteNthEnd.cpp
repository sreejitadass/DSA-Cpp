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

Node *deleteNthFromEnd(Node *head, int N)
{
    Node *fast, *slow;
    fast = slow = head;
    for (int i = 0; i < N; i++)
        fast = fast->next;
    // if N=length of list,delete first node
    if (fast == NULL)
        return head->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = delNode->next;
    free(delNode);
    return head;
}

void displayList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
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
    vector<int> arr = {1, 4, 5, 6};
    Node *head = convertToLL(arr);
    cout << "Original list:  ";
    displayList(head);
    cout << "Modified list:  ";
    head = deleteNthFromEnd(head, 2);
    displayList(head);
    return 0;
}