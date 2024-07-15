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

Node *insertAtHead(Node *head, int val)
{
    Node *newHead = new Node(val);
    if (head == NULL)
        return newHead;
    Node *temp = head;
    newHead->next = temp;
    temp->back = newHead;
    head = newHead;

    return head;
}

Node *insertBeforeK(Node *head, int val, int k)
{
    Node *newnode = new Node(val);
    if (head == NULL)
        return newnode;
    else if (k == 1)
        return insertAtHead(head, val);

    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
        {
            Node *front = temp;
            Node *prev = temp->back;
            prev->next = newnode;
            newnode->next = front;
            newnode->back = prev;
            front->back = newnode;

            break;
        }
        cnt++;
        temp = temp->next;
    }
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
    head = insertBeforeK(head, 60, 5);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}