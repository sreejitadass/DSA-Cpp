#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

class Queue
{
    int size;
    Node *front, *rear; 
public:
    Queue()
    {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x) {
        Node* newnode = new Node(x);
        if(size == 0)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        size++;
    }

    void dequeue() {
        if(front == nullptr && rear ==  nullptr)
        {
            cout<<"Queue underflow"<<endl;
        }
        else
        {
            int poppedElement = front->val;
            if(size == 1)
            {
                front = rear = nullptr;
            }
            else
            {
                Node* temp = front;
                front = temp->next;
                free(temp);
            }
            size--;
            cout<<"Popped element: "<<poppedElement<<endl;
        }
    }

    void findSize(){
        cout<<"Size: "<<size<<endl;
    }

    void display() {
        Node* temp = front;
        while(temp!=nullptr)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void peek() {
        cout<<"Peek element: "<<front->val<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.peek();
    q.findSize();

    return 0;
}