#include<iostream>
#include<queue>
using namespace std;

//Design queue operations and implement stack with that
class MyStack
{
    queue<int> q;
public:
    void push(int x)
    {
        q.push(x);
        int s = q.size();

        for(int i = 0;i<s-1;i++)
        {
            int popped = q.front();
            q.pop();
            q.push(popped);
        }
    }
    int pop()
    {
        int popped = q.front();
        q.pop();
        return popped;
    }
    int top()
    {
        return q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack s;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

    return 0;
}