#include<iostream>
#include<stack>
#include <string>
using namespace std;

string convertPrefixToInfix(const string &exp) {
    int n = exp.size();
    stack<string> s;

    for (int i = n-1; i >= 0; i--) {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z')) {
            s.push(string(1, exp[i]));
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            string top1 = s.top();
            s.pop();
            string top2 = s.top();
            s.pop();
            string x = "(" + top1 + exp[i] + top2 + ")";

            s.push(x);
        }
    }
    return s.top();
}

int main()
{
    string exp = "*+PQ-MN";
    cout<<"Infix: "<<convertPrefixToInfix(exp)<<endl;
    return 0;
}