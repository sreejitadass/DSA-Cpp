#include<iostream>
#include<vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    int count_5=0, count_10=0;
    for(int i = 0;i<n;i++){
        if(bills[i]==5){
            count_5++;
        }
        else if(bills[i]==10){
            count_10++;
            if(count_5 >= 1){
                count_5--;
            }
            else{
                return false;
            }
        }
        else{
            if(count_10 >= 1 && count_5 >=1){
                count_10--;
                count_5--;
            }
            else if(count_5 >= 3){
                count_5-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> bills = {5,5,10,10,20};
    bool result = lemonadeChange(bills);
    
    if(result){
        cout<<"Can pay change"<<endl;
    }
    else{
        cout<<"Cannot pay change"<<endl;
    }
    return 0;
}