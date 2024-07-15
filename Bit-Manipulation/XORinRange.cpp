#include <iostream>
using namespace std;

// logic in copy

int func(int N)
{
    if (N % 4 == 0)
        return N;
    else if (N % 4 == 1)
        return 1;
    else if (N % 4 == 2)
        return N + 1;
    else if (N % 4 == 3)
        return 0;
    // No need for an else statement as all cases are covered
}

int findXOR(int L, int R)
{
    return func(L - 1) ^ func(R);
}

int main()
{
    cout << "XOR in range: " << findXOR(4, 8) << endl;
    return 0;
}
