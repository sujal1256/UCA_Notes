#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getDistance(char a, char b){
        if(a == '\0' || b == '\0'){
            return 0;
        }

        return abs((a -'A')/6 - (b - 'A')/6) + abs((a - 'A')%6 - (b - 'A')%6);
    }
    int backtrackMinimumDistance(string word, int index, char f1, char f2){
        if(index == word.size()){
            return 0;
        }

        int choice1 = getDistance(word[index], f1) + backtrackMinimumDistance(word, index + 1, word[index], f2);
        int choice2 = getDistance(word[index], f2) + backtrackMinimumDistance(word, index + 1, f1, word[index]);

        return min(choice1, choice2);

    }
public:
    int minimumDistance(string word) {
        char f1 = '\0';
        char f2 = '\0';
        int i = 0;
        int ans = backtrackMinimumDistance(word, i, f1, f2);
        return ans;
    }
};


int main()
{
    Solution s;
    int ans = s.minimumDistance("HAPPY");
    cout << ans;
    
    return 0;
}