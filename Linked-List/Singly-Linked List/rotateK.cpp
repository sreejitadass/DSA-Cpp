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

int findLength(Node *head)
{
    Node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

Node *findBeforeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    return temp;
}

Node *Brute(Node *head, int k)
{
    int n = findLength(head);
    k = k % n;
    if (k == 0 || head == NULL || head->next == NULL)
        return head;
    int cnt = 0;
    while (cnt < k)
    {
        Node *beforeTail = findBeforeTail(head);
        Node *tail = beforeTail->next;
        beforeTail->next = NULL;
        tail->next = head;
        head = tail;
        cnt++;
    }
    return head;
}

Node *Optimal(Node *head, int k)
{
    if (k == 0 || head == NULL || head->next == NULL)
        return head;
    int n = findLength(head);
    Node *tail = findBeforeTail(head)->next;
    tail->next = head;
    k = k % n;
    int end = n - k;
    while (end--)
    {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    cout << "Original list:  ";
    displayList(head);
    cout << "Modified list:  ";
    head = Optimal(head, 2);
    displayList(head);
    return 0;
}