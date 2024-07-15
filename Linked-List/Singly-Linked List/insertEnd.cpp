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

Node *insertAtEnd(Node *&head, Node *&temp)
{
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
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
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node *temp = new Node(50);

    cout << "Original list:  ";
    displayList(head);
    cout << "List after insertion:  ";
    head = insertAtEnd(head, temp);
    displayList(head);
    return 0;
}
