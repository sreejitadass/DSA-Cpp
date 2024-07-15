#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

struct Stack {
    Node* top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void stackPush(int value)
    {
        Node* newnode = new Node(value);
        
        newnode->next = top;
        top = newnode;
        cout<<"Element pushed"<<endl;
        size++;
    }

    void stackPop()
    {
        if(top==NULL)
            cout<<"Stack underflow"<<endl;
        
        Node* temp = top;
        int topData = temp->data;
        top = top->next;
        free(temp);
        size--;
        cout<<"Element deleted: "<<topData<<endl;
    }

    int stackSize()
    {
        return size;
    }

    int stackPeek()
    {
        if(top==NULL)
            cout<<"Stack underflow"<<endl;
        return top->data;
    }

    bool stackIsEmpty()
    {
        return top==NULL;
    }

    void printStack()
    {
        Node* temp = top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Stack s;
    s.stackPush(10);
    s.stackPush(20);
    s.stackPush(30);
    s.printStack();
    cout<<s.stackPeek()<<endl;
    s.stackPop();
    cout<<s.stackSize()<<endl;
    s.printStack();
    s.stackPop();
    s.stackPop();
    cout<<s.stackIsEmpty();

    return 0;
}