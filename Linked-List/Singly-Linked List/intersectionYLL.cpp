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

Node *Brute(Node *head1, Node *head2)
{
    Node *t1 = head1, *t2 = head2;
    while (t1 != NULL)
    {
        Node *t2 = head2;
        while (t2 != NULL)
        {
            if (t1 == t2)
                return t2;
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return NULL;
}

Node *Optimal(Node *head1, Node *head2)
{
    unordered_map<Node *, int> mpp;
    Node *t1 = head1, *t2 = head2;
    while (t1 != NULL)
    {
        mpp[t1] = 1;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        if (mpp.find(t2) != mpp.end()) // found
        {
            return t2;
        }
        t2 = t2->next;
    }
    return NULL;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(4);

    Node *head2 = new Node(3);
    head2->next = head1->next->next->next;
    head2->next->next = head1->next->next->next->next;

    Node *intersection = Optimal(head1, head2);
    cout << "Intersecting point is: " << intersection->data << endl;
    return 0;
}