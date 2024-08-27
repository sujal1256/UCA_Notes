#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5, b = 10;
    cout << "a: " << a << endl
         << "b: " << b << endl;
    a = a^b;
    b = a^b;
    a = a^b;
    cout << "\na: " << a << endl
         << "b: " << b << endl;
    return 0;
}