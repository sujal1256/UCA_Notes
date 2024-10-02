
// https://leetcode.com/problems/top-k-frequent-elements/description/?envType=problem-list-v2&envId=heap-priority-queue

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        unordered_map<int,int> mapp;
        for(int i = 0; i < nums.size(); i++){
            mapp[nums[i]]++;
        }

        for(auto it:mapp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            } 
        }

        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

};