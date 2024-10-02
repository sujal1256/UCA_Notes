#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq;
    vector<int> v;
    int n;
    int k;


    cout << "Enter size: ";
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout<< "Enter k: ";
    cin >> k;

    for(int i = 0; i < n; i++){
        pq.push(v[i]);

        if(pq.size() > k){
            pq.pop();
        }
    }

    while(pq.size()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}