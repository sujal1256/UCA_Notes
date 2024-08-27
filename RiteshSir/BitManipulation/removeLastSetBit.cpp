#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100; // 1100100
    //  here n - 1 = 100011
    // If we do n&(n-1) it will remove the last bit
    n = n & (n - 1);
    cout << n << endl;
    return 0;
}