#include<iostream>
#include<stack>
using namespace std;

void deleteMidElement(stack<int>&s, int count, int size)
{
    //base case
    if(count == size/2)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    deleteMidElement(s, count+1, size);
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
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMidElement(s, 0, s.size());
    printStack(s);
    return 0;
}