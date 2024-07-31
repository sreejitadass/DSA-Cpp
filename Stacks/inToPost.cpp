#include<iostream>
#include<stack>
using namespace std;

int priority(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x=='/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

string convertInfixToPostfix(string exp)
{
    int n = exp.size();
    int i = 0;
    stack<char>s;
    string ans="";
    while(i<n)
    {
        //1.for operand
        if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
        {
            ans+=exp[i];
        }
        //2.for (
        else if(exp[i] == '(')
        {
            s.push(exp[i]);
        }
        //3.for )
        else if(exp[i] == ')')
        {
            while(!s.empty() && s.top()!='(')
            {
                ans+=s.top();
                s.pop();
            }
            s.pop();    //pop out the corresponding (
        }
        //4.for operator
        else
        {
            while(!s.empty() && s.top()!='(' && priority(exp[i]) <= priority(s.top()))
            {
                ans+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        i++;
    }
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    string exp = "a+b*(c^d-e)";
    string ans = convertInfixToPostfix(exp);
    cout<<"Postfix: "<<ans<<endl;
    return 0;
}