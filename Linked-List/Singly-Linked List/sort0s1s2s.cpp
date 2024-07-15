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

Node *sortList(Node *head)
{
    Node *temp = head, *zerohead, *onehead, *twohead, *zeroes, *ones, *twos;
    zerohead = new Node(-1);
    onehead = new Node(-1);
    twohead = new Node(-1);
    zeroes = zerohead, ones = onehead, twos = twohead;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroes->next = temp;
            zeroes = temp;
        }
        else if (temp->data == 1)
        {
            ones->next = temp;
            ones = temp;
        }
        else
        {
            twos->next = temp;
            twos = temp;
        }
        temp = temp->next;
    }
    zeroes->next = (onehead->next) ? (onehead->next) : (twohead->next);
    ones->next = twohead->next;
    twos->next = NULL;
    Node *sortedhead = zerohead->next;
    free(zerohead);
    free(onehead);
    free(twohead);

    return sortedhead;
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
    vector<int> arr = {0, 0, 2, 1, 2, 0, 1, 2, 1};
    Node *head = convertToLL(arr);
    cout << "Original list:  ";
    displayList(head);
    cout << "Modified list:  ";
    head = sortList(head);
    displayList(head);
    return 0;
}