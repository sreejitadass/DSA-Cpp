#include<iostream>
using namespace std;

struct Stack
{
    int MAX_SIZE;
    int *stack;
    int top;

    Stack()
    {
        MAX_SIZE = 100;
        stack = new int[MAX_SIZE];
        top = -1;
    }

    void stackPush(int value)
    {
        top++;
        if(top == MAX_SIZE)
            cout<<"Stack overflow"<<endl;
        stack[top] = value;
        cout<<"Element pushed"<<endl;
    }

    void stackPop()
    {
        if(top==-1)
            cout<<"Stack underflow"<<endl;
        int topData = stack[top];
        top--;
        cout<<"Element deleted: "<<topData<<endl;
    }

    int stackSize()
    {
        return top+1;
    }

    int stackPeek()
    {
        return stack[top];
    }

    bool stackIsEmpty()
    {
        return top==-1;
    }

    void printStack()
    {
        for(int i = 0; i<=top ; i++)
        {
            cout<<stack[i]<<" ";
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