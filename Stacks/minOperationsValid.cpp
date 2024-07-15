#include<iostream>
#include<stack>
using namespace std;

int findMinCostToMakeValid(string expression)
{
    if(expression.size()%2!=0)
        return -1;
    
    int open = 0, close = 0;
    stack<char>s;

    for(int i =0; i<expression.size(); i++)
    {
        char ch = expression[i];
        if(ch == '{')
            s.push(ch);
        else
        {
            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
        }
    }

    //invalid case
    while(!s.empty())
    {
        char top = s.top();
        if(top == '{')
            open++;
        else
            close++;
        s.pop();
    }
    int minOperations = ((open+1)/2) + ((close+1)/2);
    
    return ((open!=0 && close!=0) && (open%2!=0 && close%2!=0))? minOperations-1 : minOperations;
}

int main()
{
    string expression = "{{{{";
    cout<<"Minimum operations: "<<findMinCostToMakeValid(expression)<<endl;
    return 0;
}