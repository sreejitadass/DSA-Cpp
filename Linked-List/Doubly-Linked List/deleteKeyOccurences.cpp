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
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->back = NULL;
    }
    delete temp;
    return head;
}

Node *deleteKeys(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = deleteHead(temp);
                temp = head;
            }
            else
            {
                Node *delNode = temp;
                Node *prev = delNode->back;
                Node *front = delNode->next;
                prev->next = front;
                if (front != NULL)
                {
                    front->back = prev;
                }
                temp = temp->next;
                delete delNode;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

Node *convertArr2LL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
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
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    Node *head = convertArr2LL(arr);
    cout << "Original list:  ";
    displayList(head);
    head = deleteKeys(head, 10);
    cout << "Modified list:  ";
    displayList(head);
    return 0;
}
