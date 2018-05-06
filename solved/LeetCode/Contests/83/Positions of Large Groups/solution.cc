class Solution {
  public:
    vector<vector<int>> largeGroupPositions(string S) {
      char last = '*';
      int cur_len = 0;
      vector<pair<int, int>> partial;
      int i = 0;
      for (auto it : S) {
        if (it == last) {
          cur_len++;
        } else {
          partial.emplace_back(cur_len, i - 1);
          cur_len = 1;
        }
        last = it;
        i++;
      }
      partial.emplace_back(cur_len, S.size() - 1);
      vector<vector<int>> ans;
      for (auto it : partial) {
        if (it.first > 2) {
          vector<int> tmp = {it.second - it.first + 1, it.second};
          ans.push_back(tmp);
        }
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};
