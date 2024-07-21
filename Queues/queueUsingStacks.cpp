#include<iostream>
#include<stack>
using namespace std;

class MyQueue
{
    stack<int>s1, s2;
public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int size = s1.size();
        for(int i = 0; i<size-1; i++)
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int popped = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }

        return popped;
    }

    int peek()
    {
        int size = s1.size();
        for(int i = 0; i<size-1; i++)
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int popped = s1.top();

        while(!s2.empty())
        {
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }

        return popped;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}