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

Node *findMiddle(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    temp->next = (left != NULL) ? left : right;
    Node *result = dummy->next;
    delete dummy; // Free the dummy node
    return result;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = findMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL; // separate the list into two halves

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
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
    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);

    Node *mergedHead = mergeSort(head);
    displayList(mergedHead);
    return 0;
}
