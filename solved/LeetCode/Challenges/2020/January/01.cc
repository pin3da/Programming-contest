#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    int idx = 0;
    while (idx < arr.size()) {
      int p_id = -1;
      for (int i = 0; i < pieces.size(); i++) {
        if (pieces[i][0] == arr[idx]) {
          p_id = i;
          break;
        }
      }
      if (p_id == -1) {
        return false;
      }
      for (int j = 0; j < pieces[p_id].size(); j++) {
        if (arr[idx] != pieces[p_id][j]) {
          return false;
        }
        idx++;
      }
    }
    return idx == arr.size();
  }
};
