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

Node *reverseList(Node *head)
{
    Node *prev, *curr, *front;
    prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node *Brute(Node *head)
{
    head = reverseList(head);
    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    head = reverseList(head);
    if (carry == 1)
    {
        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    else
    {
        return head;
    }
}

int helper(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        return 1;                   // base case
    int carry = helper(temp->next); // o/w go deeper
    temp->data += carry;
    if (temp->data < 10)
    {
        return 0;
    }
    else
    {
        temp->data = 0;
        return 1;
    }
}

Node *Optimal(Node *head)
{
    int finalCarry = helper(head);
    if (finalCarry == 1)
    {
        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    else
    {
        return head;
    }
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
        cout << curr->data << "";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {9, 9, 9, 9, 9};
    Node *head = convertArr2LL(arr);
    head = Optimal(head);
    cout << "Number after adding 1:  ";
    displayList(head);
    return 0;
}