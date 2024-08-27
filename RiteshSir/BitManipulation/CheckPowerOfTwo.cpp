#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100; // 1100100
    // to check if it is a power of 2 or not
    // power of 2 always have 1 set bit
    // if we remove last set bit, the number will be 0

    // int n = 128;

    n = n & (n - 1);
    if (n == 0)
        cout << "Number is a power of 2";
    else
        cout << "Number is not a power of 2";
    return 0;
}