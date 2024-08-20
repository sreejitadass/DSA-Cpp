#include<iostream>
#include<stack>
using namespace std;

int maxDepth(string s) {
    int cnt=0;
    int maxCnt=0;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            cnt++;
            maxCnt=max(maxCnt,cnt);
        }
        else if(s[i]==')'){
            cnt--;
        }      
    }
    return maxCnt;
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<"Max depth of parantheses: "<<maxDepth(s)<<endl;
    return 0;
}