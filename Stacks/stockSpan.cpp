#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

/*Brute-Force*/
// class StockSpanner {
//     vector<int>arr;
// public:
//     StockSpanner() {
//         arr={};
//     }
    
//     int next(int price) {
//        arr.push_back(price);
//        int count=0;
//        for(int i = arr.size()-1;i>=0;i--)
//        {
//           if(arr[i]<=price)
//             count++;
//        }
//        return count;
//     }
// };

/*Optimized*/
class StockSpanner {
    stack<pair<int,int>>s;
    int index;
public:
    StockSpanner() {
        s = {};
        index = -1;
    }
    
    int next(int price) {
       index++;
       //PGE
       //Formula: PGE_index - current_index
       while(!s.empty() && s.top().first <= price)
       {
            s.pop();
       }
       int ans = (index-(s.empty() ? -1: s.top().second));
       s.push({price,index});
       return ans;
    }
};

int main()
{
    StockSpanner stocks;
    cout<<stocks.next(100)<<endl;
    cout<<stocks.next(80)<<endl;
    cout<<stocks.next(60)<<endl;
    cout<<stocks.next(70)<<endl;
    cout<<stocks.next(60)<<endl;
    cout<<stocks.next(75)<<endl;
    cout<<stocks.next(85)<<endl;
    return 0;
}