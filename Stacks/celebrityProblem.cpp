#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>>&matrix,int A,int B)
{
    return matrix[A][B];
}

int findTheCelebrity(vector<vector<int>>&matrix, int n)
{
    stack<int>s;

    //push all persons to stack
    for(int i = 0;i<n;i++)
    {
        s.push(i);
    }

    //find potential celebrity candidate
    while(!(s.size()==1))
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        //A knows B
        if(knows(matrix,A,B))
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }
    int candidate = s.top();
    
    //last check for celebrity
    bool rowChecked = false;
    bool colChecked = false;
    int zeroesCnt=0,onesCnt=0;

    //row check
    for(int i = 0;i< n;i++)
    {
        if(matrix[candidate][i]==0)
            zeroesCnt++;
    }

    if(zeroesCnt==n)
        rowChecked = true;
    
    //column check
    for(int i = 0;i< n;i++)
    {
        if(matrix[i][candidate]==1)
            onesCnt++;
    }

    if(onesCnt==n-1)
        colChecked = true;

    if(rowChecked && colChecked)
        return candidate;
    else
        return -1;
}

int main()
{
    vector<vector<int>>matrix = {{0,1,0},{0,0,0},{0,1,0}};
    int n = matrix.size()-1;
    cout<<"Celebrity: "<<findTheCelebrity(matrix,n)<<endl;
    return 0;
}