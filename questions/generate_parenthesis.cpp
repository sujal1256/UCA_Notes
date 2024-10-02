#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void solve(int n, set<string> &s, string str)
{
    if (n == 0)
    {
        s.insert(str);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string a = str;
        a.insert(a.begin() + i, '(');
        a.insert(a.begin() + i + 1, ')');
        solve(n - 1, s, a);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout <<  "()";
        return 0;
    }
    set<string> s;
    string str = "()";
    solve(n - 1, s, str);
    for (auto i : s)
    {
        cout << i << ' ';
    }

    return 0;
}