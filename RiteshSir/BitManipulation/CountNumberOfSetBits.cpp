#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100; // 1100100

    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        // clearing the last set bit
        n = n & (n - 1);
    }

    cout<<cnt<<endl;

    return 0;
}