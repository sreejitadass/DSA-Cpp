#include <iostream>
#include <vector>
using namespace std;

/*
n-->length of merged array
1)if n is even--> median index: n/2,(n/2-1)
2)if n is odd--> median index: n/2
*/

int findMedian(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    int i = 0, j = 0;
    int n = n1 + n2;
    int ind1 = n / 2, ind2 = ind1 - 1;
    int count = 0; // index tracker
}