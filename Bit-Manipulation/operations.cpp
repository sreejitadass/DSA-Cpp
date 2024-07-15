#include <iostream>
using namespace std;

bool checkIfSetBit(int N, int i)
{
    return (N & (1 << i) != 0);
}

int setBit(int N, int i)
{
    return (N | (1 << i));
}

int clearBit(int N, int i)
{
    return (N & ~(1 << i));
}

int toggleBit(int N, int i)
{
    return (N ^ (1 << i));
}

int removeLastSetBit(int N, int i)
{
    return (N & (N - 1));
}

bool checkIfPowerOf2(int N)
{
    return ((N & (N - 1)) == 0);
}

int countSetBits(int N)
{
    int c = 0;
    while (N != 0)
    {
        N = N & (N - 1); // remove/clear/toggle last set bit everytime
        c++;
    }
    return c;
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int N = 13, i = 2, a = 5, b = 7;
    cout << "Bit set: " << checkIfSetBit(N, i) << endl;
    cout << "After setting bit: " << setBit(N, i) << endl;
    cout << "After clearing bit: " << clearBit(N, i) << endl;
    cout << "After toggling bit: " << toggleBit(N, i) << endl;
    cout << "After removing last set bit: " << removeLastSetBit(N, i) << endl;
    cout << "Power of 2: " << checkIfPowerOf2(16) << endl;
    cout << "Number of set bits: " << countSetBits(N) << endl;

    cout << "Before swapping: " << a << " " << b << endl;
    swap(a, b);
    cout << "After swapping: " << a << " " << b << endl;

    return 0;
}