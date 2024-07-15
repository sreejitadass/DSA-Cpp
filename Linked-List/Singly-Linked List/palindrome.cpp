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

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool isPalindrome(Node *head)
{
    Node *mid = findMiddle(head);
    Node *newhead = reverseList(mid->next);
    Node *first = head, *second = newhead;
    if (head == NULL || head->next == NULL)
        return true;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseList(newhead);
            return false;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
    reverseList(newhead);
    return true;
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

int main()
{
    vector<int> arr = {1, 2, 5, 3, 2, 1};
    Node *head = convertArr2LL(arr);
    if (isPalindrome(head))
        cout << "It is a palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;
    return 0;
}