#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    int n = v.size();

    // Get the number of subsets
    int numSub = (1 << n);
    vector<vector<int>> ans;
    for (int num = 0; num < numSub; num++)
    {
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            // If the ith bit is set then
            // add it in the vector
            if (num & (1 << i))
            {
                arr.push_back(v[i]);
            }
        }
        ans.push_back(arr);
    }

    for (auto it : ans)
    {
        for (int i : it)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}