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

/*
Brute-->

Node *findStartingPointLoop(Node *head)
{
    unordered_map<Node *, int> mpp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        { // found
            return temp;
        }
        mpp[temp] = 1; // mark as visited
        temp = temp->next;
    }
    return NULL;
}
*/

/*
Optimal-->
*/
Node *findStartingPointLoop(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // 1st collision
        {
            slow = head;
            while (slow != fast) // 2nd collision
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next = head->next->next;

    Node *start = findStartingPointLoop(head);
    if (start == NULL)
        cout << "Loop not found" << endl;
    else
        cout << "Starting point of loop: " << start->data << endl;
    return 0;
}