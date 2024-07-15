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

/*Brute force: O(n)

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *deleteMidNode(Node *head)
{
    Node *mid = findMiddle(head);
    Node *afterMid = mid->next;
    Node *beforeMid = head;
    while (beforeMid->next != mid)
    {
        beforeMid = beforeMid->next;
    }
    beforeMid->next = afterMid;
    free(mid);
    return head;
}
*/

/*
Optimal: O(n/2)
TORTOISE AND HARE
*/

Node *deleteMidNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head, *fast = head, *mid;
    fast = fast->next->next; // skipping 1 step of slow so that it is at beforeMid
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow->next;
    slow->next = mid->next;
    free(mid);
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
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    Node *head = convertToLL(arr);
    cout << "Original list:  ";
    displayList(head);
    cout << "Modified list:  ";
    head = deleteMidNode(head);
    displayList(head);
    return 0;
}