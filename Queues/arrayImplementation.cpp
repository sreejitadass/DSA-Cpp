#include<iostream>
using namespace std;

class Queue
{
    int MAX_SIZE;
    int currsize, start, end;
    int *a;
public:
    Queue(int MAX_SIZE)
    {
        a = new int[MAX_SIZE],
        start=-1,
        end=-1,
        currsize=0;
    }

    void push(int x)
    {
        if(currsize == MAX_SIZE)
        {
            cout<<"Queue overflow"<<endl;
        }
        if(end == -1)
        {
            end = 0;
            start = 0;
        }
        else
        {
            end=(end+1)%MAX_SIZE;
        }
        a[end] = x;
        currsize++;
    }

    void pop()
    {
        if(start == -1 && end == -1)
        {
            cout<<"Queue underflow"<<endl;
        }
        else
        {
            int poppedElement = a[start];
            if(currsize == 1)
            {
                start = end = -1;
                currsize = 0;
            }
            else
            {
                start = (start+1)%MAX_SIZE;
                currsize--;
            }
            cout<<"Popped element is: "<<poppedElement;
        }
    }

    void size()
    {
        cout<<"Queue size: "<<currsize;
    }

    void peek()
    {
        if(end == -1)
            cout<<"Queue underflow"<<endl;
        else
            cout<<"Peek element: "<<a[start]<<endl;
    }

    void display()
    {
        cout<<endl;
        if(currsize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = start;
        do
        {
            cout << a[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (end + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main()
{
    Queue q(30);
    q.push(7);
    q.push(8);
    q.pop();
    q.display();
    q.peek();
    q.push(10);
    q.display();
}