#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    string str;
    while (n != 1)
    {
        str += to_string(n % 2);
        n = n / 2;
    }
    str += to_string(n);
    reverse(str.begin(), str.end());
    cout << "Binary:" << endl
         << str << endl;
    return 0;
}