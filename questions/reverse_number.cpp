#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sign = 1;

    if( n < 0 ){
        sign = -1;
    }
    n = abs(n);
    int rev = 0;
    cout << "n is " << n << endl;
    while(n > 0){
        int rem = n%10;
        // rev*10 + rem >= INT_MAX
        if(rev > (INT_MAX - rem)/10){
            cout << 0;
            return 0;
        }
        rev = rev*10 + rem;
        n = n/10;
    }
    cout << rev*sign;
    return 0;
}