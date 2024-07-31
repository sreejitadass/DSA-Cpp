#include<iostream>
#include<stack>
#include<utility>
using namespace std;

class MinStack
{
    stack<pair<int,int>> s;     //{element, min}
public:
    void push(int x)
    {
        int mini;
        if(s.empty())
        {
            mini = x;
            s.push({x, mini});
        }
        else
        {
            mini = min(x, s.top().second);
            s.push({x, mini});
        }
        //top stores the minimum element
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

int main()
{
    MinStack s;
    s.push(2);
    s.push(-6);
    s.push(3);
    s.push(11);
    s.push(9);
    s.push(-17);
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Min element: "<<s.getMin()<<endl;

    return 0;
}