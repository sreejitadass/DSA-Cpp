#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>&wordList)
{
    //store in set to erase when needed for visited purposes
    queue<pair<string,int>>q;
    q.push({beginWord, 1});     //{word,level}
    set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while(!q.empty())
    {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        //if target is reached
        if(word==endWord)
            return level;

        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch = 'a'; ch<='z';ch++)
            {
                word[i]=ch;
                //if found in set, mark as visited and push to queue
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word, level+1});
                }
            }
            //if not found change the word to original
            word[i]=original;
        }
    }
    return 0;
}

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList ={"hot","dot","dog","lot","log","cog"};
    cout<<"Minimum steps: "<<ladderLength(beginWord,endWord,wordList)<<endl;
    return 0;
}