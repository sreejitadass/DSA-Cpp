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

Node *add2(Node *head1, Node *head2)
{
    int carry = 0, sum = 0;
    Node *t1 = head1, *t2 = head2, *dummy = new Node(-1), *temp = dummy;
    while (t1 != NULL || t2 != NULL)
    {
        int sum = 0;
        if (t1 != NULL)
        {
            sum += t1->data;
            t1 = t1->next;
        }
        if (t2 != NULL)
        {
            sum += t2->data;
            t2 = t2->next;
        }

        sum += carry; // first digit
        carry = sum / 10;
        sum = sum % 10; // last digit
        Node *sumNode = new Node(sum);

        temp->next = sumNode;
        temp = temp->next;
    }
    return dummy->next;
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
    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node *newhead = add2(head1, head2);
    cout << "Addition: ";
    displayList(newhead);
    return 0;
}