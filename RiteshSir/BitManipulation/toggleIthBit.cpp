#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100; // 1100100
    int i = 2;
    n = (1 << i - 1) ^ n;
    cout << n << endl;
    return 0;
}