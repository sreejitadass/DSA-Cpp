#include<iostream>
#include<stack>
#include <string>
using namespace std;

string convertPostfixToInfix(const string &exp) {
    int n = exp.size();
    stack<string> s;

    for (int i = 0; i < n; i++) {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z')) {
            s.push(string(1, exp[i]));
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            string top1 = s.top();
            s.pop();
            string top2 = s.top();
            s.pop();
            string x = "(" + top2 + exp[i] + top1 + ")";

            s.push(x);
        }
    }
    return s.top();
}

int main()
{
    string exp = "AB-DE+F*/";
    cout<<"Infix: "<<convertPostfixToInfix(exp)<<endl;
    return 0;
}