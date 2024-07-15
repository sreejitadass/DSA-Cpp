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

Node *removeDuplicatesSorted(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode->data == temp->data && nextNode->next != NULL)
        {
            Node *dup = nextNode;
            nextNode = nextNode->next;
            free(dup);
        }
        temp->next = nextNode;
        if (nextNode != NULL)
            nextNode->back = temp;
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
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    cout << "Original list:  ";
    displayList(head);
    head = removeDuplicatesSorted(head);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}