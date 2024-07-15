#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>&wordList)
{

}

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList ={"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);

    cout<<"Word ladders: "<<endl;
    for(auto i: ans)
    {
        for(string j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}