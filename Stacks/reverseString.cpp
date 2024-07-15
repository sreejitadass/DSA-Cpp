#include<iostream>
#include<stack>
using namespace std;

string reverseString(string word)
{
    stack<char>s;

    for(int i = 0;i<word.size();i++)
        s.push(word[i]);

    int i = 0;
    while(!s.empty())
    {
        word[i] = s.top();
        s.pop();
        i++;
    }
    return word;
}

int main()
{
    string word = "hello world";
    cout<<"Reversed word: "<<reverseString(word)<<endl;
    return 0;
}