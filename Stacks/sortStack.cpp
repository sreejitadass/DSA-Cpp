#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>&s, int num)
{
    //base case
    if(s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    
    //recursion
    sortedInsert(s, num);
    s.push(temp);
}

void sortStack(stack<int>&s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    sortStack(s);
    sortedInsert(s, temp);
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
    s.push(-5);
    s.push(9);
    s.push(-4);
    s.push(-11);
    s.push(17);
    s.push(21);

    sortStack(s);
    printStack(s);
    return 0;
}