#include<iostream>
#include<stack>
using namespace std;

bool checkRedundantParantheses(string expression) {
    stack<char> s;

    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            s.push(ch);
        } else if (ch == ')') {
            bool isRedundant = true;
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                s.pop();
            }
            if (!s.empty()) {
                s.pop(); // pop the matching opening bracket '('
            }
            if (isRedundant) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string expression = "((a/b)+x)";
    cout<<"Redundant parantheses: "<<checkRedundantParantheses(expression)<<endl;
    return 0;
}