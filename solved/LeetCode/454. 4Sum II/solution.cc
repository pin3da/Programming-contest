class Solution {
  public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> left, right;
      for (auto it : A)
        for (auto it2 : B)
          left[it + it2]++;

      for (auto it : C)
        for (auto it2 : D)
          right[it + it2]++;

      int ways = 0;

      for (auto l : left)
        ways += l.second * right[-l.first];

      return ways;
    }
};
