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

Node *deleteNode(Node *head, int val)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            Node *delNode = temp;
            delNode->back->next = delNode->next;
            delNode->next->back = delNode->back;
            delNode->next = delNode->back = NULL;
            free(delNode);

            break;
        }
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
    head = deleteNode(head, 20);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}