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
int findLoopLength(Node *head)
{
    unordered_map<Node *, int> mpp;
    Node *temp = head;
    int count = 1, value;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        { // found
            value = mpp[temp];
            return (count - value) + 1;
        }
        mpp[temp] = count; // mark as visited
        count++;
        temp = temp->next;
    }
    return 0;
}
*/

/*
Optimal-->
*/

int findLength(Node *fast, Node *slow)
{
    int count = 1;
    fast = fast->next;
    while (slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count + 1;
}

int findLoopLength(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return findLength(fast, slow);
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next = head->next->next;

    cout << "Length of loop: " << findLoopLength(head) << endl;
    return 0;
}