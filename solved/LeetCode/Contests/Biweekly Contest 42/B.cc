#include <bits/stdc++.h>
#include "./template.cc"
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double ans = 0;
        int cur = 0;
        for (auto it : c) {
            int arr = it[0];
            int prep = it[1];
                ans += prep;
            if (arr < cur) {
                ans += (cur - arr);
            }
            cur = max(cur + prep, arr + prep);
        }
        return ans / c.size();
    }
};

struct Input {
  vector<vector<int>> c;
};

int main() {
    vector<Input> in = {
        {
            {{1,2},{2,5},{4,3}}
        },
        {
            {{5,2},{5,4},{10,3},{20,1}}
        }
    };

    for (auto &it : in) {
        Solution sol;
        print(cout, sol.averageWaitingTime(it.c));
    }
}