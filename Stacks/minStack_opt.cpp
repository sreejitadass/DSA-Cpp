#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
    stack<int>s;
    int mini;
public: 
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int x)
    {
        if(s.empty())
        {
            mini = x;
            s.push(x);
        }
        else if(x > mini)
        {
            s.push(x);
        }
        else
        {
            s.push(2*x - mini);
            mini = x;
        }
    }

    void pop()
    {
        if(s.top() < mini)
        {
            mini = 2*mini - (s.top());
            s.pop();
        }
        else
        {
            s.pop();
        }
    }

    int top()
    {
        if(s.top() < mini)
        {
            return mini;
        }
        else
        {
            return s.top();
        }
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    MinStack s;
    s.push(2);
    s.push(-6);
    s.push(3);
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Min element: "<<s.getMin()<<endl;

    return 0;
}