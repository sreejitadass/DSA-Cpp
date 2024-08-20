#include<iostream>
#include<algorithm>
using namespace std;

// bool rotateString(string s, string goal) {
//     char start = s[0];
//     int startIdxGoal = 0;
//     for(int i = 0;i<goal.size();i++){
//         if(goal[i] == start){
//             startIdxGoal = i;
//             break;
//         }
//     }  

//     int n = s.size();  
//     int k = n - startIdxGoal+1;  

//     reverse(goal.begin(), goal.begin() + k);
//     cout<<goal<<endl;
//     reverse(goal.begin()+k, goal.begin() + n);
//     cout<<goal<<endl;
//     reverse(goal.begin(), goal.begin() + n);
//     cout<<goal<<endl;

//     return s==goal;
// }

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    string concatenated = goal + goal;
    return concatenated.find(s) != string::npos;
}


int main()
{
    cout<<rotateString("abcde","abced");
    return 0;
}