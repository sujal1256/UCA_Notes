#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "1100100";
    int ans = 0;
    int p = 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        ans += (str[i] - '0')?p:0;
        p = p * 2;
    }
    cout << ans << endl;
    return 0;
}