#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

void storeGraph(int n,vector<vector<int>>&mat,vector<vector<int>>&edges)
{
    for(auto it: edges)
    {
        //mat[u][v]=w
        mat[it[0]][it[1]] = it[2];
        mat[it[1]][it[0]] = it[2];
    }
}

int findTheCity(int n, vector<vector<int>>&edges, int distanceThreshold)
{
    vector<vector<int>>mat(n,vector<int>(n,1e9));
    storeGraph(n,mat,edges);

    //Floyd-Warshall algo to fill up the distance grid
    for(int i=0;i<n;i++)
    {
        mat[i][i]=0;
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //i..j via k
                if(mat[i][k]==1e9 || mat[k][j]==1e9)
                    continue;
                mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }

    //to find min city
    int cntMax = n;
    int city = -1;
    for(int i=0;i<n;i++)
    {
        int cnt=0;      //for each row
        for(int j=0;j<n;j++)
        {
           if(mat[i][j] <= distanceThreshold) 
           {
                cnt++;
           }
        }
        if(cnt<=cntMax)
        {
            //min city neighbours
            cntMax=cnt;
            city = i;
        }
    }
    return city;
}

int main()
{
    int n=4;
    vector<vector<int>>edges = {{0,1,3},{1,2,1},{2,3,1},{3,1,4}};
    cout<<"City number: "<<findTheCity(n,edges,4)<<endl;
    return 0;
}