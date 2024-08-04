#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    stack<int>s;
    int n = asteroids.size();
    for(int i = 0;i<n;i++)
    {
        if(asteroids[i]>0)
        {
            s.push(asteroids[i]);
        }
        else
        {
            while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
            {
                s.pop();
            }
            if(!s.empty() && s.top()==abs(asteroids[i]))
            {
                s.pop();
            }
            else if(s.empty() || s.top()<0)
            {
                s.push(asteroids[i]);
            }
        }
    }
    vector<int>ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    vector<int>asteroids = {4,7,1,1,2,-3,-7,17,15,-18,-19};
    vector<int>ans = asteroidCollision(asteroids);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}