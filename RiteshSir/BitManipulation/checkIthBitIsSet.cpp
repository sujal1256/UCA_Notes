// Here, in this we are going to check if ith bit is set or not

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// in n = 100, 1100100
// if we want to check 3rd bit from right is set or not
int main()
{
    int n = 100;
    // ith bit from right
    int i = 3;
    // n = n >> (i - 1);
    // cout << n << endl;
    // if (n & 1)
    //     cout << "Set";
    // else
    //     cout << "Clear";

    if ((n >> (i - 1)) & 1)
    {
        cout << "Set" << endl;
    }
    else
    {
        cout << "Cleared" << endl;
    }

    // there is also a way we can make 1(i-1 0s)
    // 100 make & to the n

    if ((1 << i - 1) & n)
    {
        cout << "Set" << endl;
    }
    else
    {
        cout << "Cleared" << endl;
    }

    return 0;
}