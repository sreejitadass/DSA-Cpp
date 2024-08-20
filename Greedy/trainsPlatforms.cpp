#include<iostream>
#include<algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int i=0,j=0;
    int cnt=0,maxCnt=0;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main() {
    int arr[] = {900, 1235, 1100};
    int dep[] = {1000, 1240, 1200};
    int n = 3;
    cout << "Platforms required: " << findPlatform(arr, dep, n) << endl;
    return 0;
}
