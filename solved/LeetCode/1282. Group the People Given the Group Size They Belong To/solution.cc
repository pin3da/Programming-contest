#include <bits/stdc++.h>

using namespace std;

#include "template.cc"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       vector<pair<int, int>> data;
       for (int i = 0; i < groupSizes.size(); i++) {
           data.emplace_back(groupSizes[i], i);
       }
       sort(data.begin(), data.end());
       vector<vector<int>> ans;
       vector<int> cur;
       for (auto it: data) {
           debug(it);
           cur.push_back(it.second);
           if (cur.size() + 1 > it.first) {
               ans.push_back(cur);
               cur = {};
           }
       }
       if (!cur.empty()) {
           ans.push_back(cur);
       }
       return ans;
    }
};

int main() {
    Solution sol;
    // vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<int> groupSizes = {2,1,3,3,3,2};
    debug(sol.groupThePeople(groupSizes));
}
