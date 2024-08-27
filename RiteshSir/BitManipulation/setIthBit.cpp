#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// in 100, 1100100 to set 4th bit from right ( | ) with 10000
int main()
{
    int n = 100;
    int i = 4;
    n = (1 << (i - 1)) | n;

    cout << n << endl;

    cout << "\nClearing ith bit" << endl;
    // simply & with the 0 at 4th bit
    n = ~(1 << (i - 1)) & n;
    cout << n << endl;
    return 0;
}