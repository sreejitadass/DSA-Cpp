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

bool detectLoop(Node *head)
{
    unordered_map<Node *, int> mpp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        { // found
            return true;
        }
        mpp[temp] = 1; // mark as visited
        temp = temp->next;
    }
    return false;
}
*/

/*
Optimal-->
*/
bool detectLoop(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    if (detectLoop(head))
        cout << "Loop found" << endl;
    else
        cout << "Loop not found" << endl;
    return 0;
}