#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s, int element, int count, int size)
{
    //base case
    if(count==size)     //or, if(s.empty())
    {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    insertAtBottom(s, element,count+1, size);
    s.push(temp);
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
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    int element = 9;
    int count = 0, size = s.size();

    insertAtBottom(s, element, count, size);
    printStack(s);
    return 0;
}