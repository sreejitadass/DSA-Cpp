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

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    head->next->back = NULL;
    head = head->next;
    free(temp);

    return head;
}

Node *deleteKthelement(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    else if (k == 1)
    {
        return deleteHead(head);
    }
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
        {
            Node *delNode = temp;
            delNode->back->next = delNode->next;
            delNode->next->back = delNode->back;
            delNode->next = delNode->back = NULL;
            free(delNode);

            break;
        }
        cnt++;
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
    vector<int> arr = {4, 5, 2, 11};
    Node *head = convertArr2LL(arr);
    cout << "Original list:  ";
    displayList(head);
    head = deleteKthelement(head, 1);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}