#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s, int element)
{
    //base case
    if(s.empty())    
    {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    insertAtBottom(s, element);
    s.push(temp);
}

void reverseStack(stack<int>&s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    reverseStack(s);
    //insert at bottom the temp element(at end, after return in base case)
    insertAtBottom(s,temp);
}

void printStack(stack<int>&s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);
    printStack(s);
    return 0;
}