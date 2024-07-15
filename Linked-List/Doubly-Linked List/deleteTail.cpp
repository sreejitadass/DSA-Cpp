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

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *tail = head; // before tail
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newtail = tail->back;
    newtail->next = NULL;
    tail->back = NULL;
    free(tail);

    return head;
}

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
        temp = temp->next;
    }
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

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    Node *head = convertArr2LL(arr);
    cout << "Original list:  ";
    displayList(head);
    head = deleteTail(head);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}