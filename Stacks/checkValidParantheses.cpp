#include<iostream>
#include<stack>
using namespace std;

bool checkIfValidExpression(string expression)
{
    stack<char>s;
    for(int i = 0;i<expression.size();i++)
    {
        char ch = expression[i];
        //if opening brackets, push to stack
        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            if(!s.empty() && s.top() == '(')
                s.pop();
            else
                return false;
        }
        else if(ch == '}')
        {
            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                return false;
        }
        else
        {
            if(!s.empty() && s.top() == '[')
                s.pop();
            else
                return false;
        }        
    }
    return s.empty();
}

int main()
{
    string expression = "(((())))";
    cout<<"Valid: "<<checkIfValidExpression(expression)<<endl;
    return 0;
}