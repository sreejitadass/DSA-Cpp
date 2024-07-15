#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<vector<int>>findShortestDistances(int n, vector<vector<int>>&adjMatrix)
{
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i==j)
                adjMatrix[i][j]=0;
            if(adjMatrix[i][j]==-1)
                adjMatrix[i][j]=1e9;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //i..j via k
                adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(adjMatrix[i][j]==1e9)
                adjMatrix[i][j]=-1;
        }
    }
    return adjMatrix;
}

int main()
{
    int n = 4;
    vector<vector<int>>adjMatrix(n,vector<int>(n,-1));
    adjMatrix[0][1]=2;
    adjMatrix[1][0]=1;
    adjMatrix[1][2]=3;
    adjMatrix[3][0]=3;
    adjMatrix[3][1]=5;
    adjMatrix[3][2]=4;

    vector<vector<int>>ans = findShortestDistances(n,adjMatrix);
    cout<<"Shortest distances: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}