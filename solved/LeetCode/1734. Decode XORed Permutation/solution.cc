class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    vector<int> ans(encoded.size() + 1);
    int extra = ((ans.size() + 1) / 2) & 1;
    for (int i = 1; i < encoded.size(); i+=2) {
      extra ^= encoded[i];
    }
    ans[0] = extra;
    for (int i = 1; i < ans.size(); i++) {
      ans[i] = ans[i-1] ^ encoded[i-1];
    }
    return ans;
  }
};
