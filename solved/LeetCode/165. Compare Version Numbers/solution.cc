class Solution {
  vector<int> parse(string version) {
    vector<int> ans;
    int current = 0;
    for (auto it : version) {
      if (it == '.') {
        ans.push_back(current);
        current = 0;
      } else {
        current = 10 * current + (it - '0');
      }
    }
    ans.push_back(current);
    return ans;
  }

  public:
  int compareVersion(string version1, string version2) {
    vector<int> v1 = parse(version1), v2 = parse(version2);
    size_t len = max(v1.size(), v2.size());
    while (v1.size() < len) v1.push_back(0);
    while (v2.size() < len) v2.push_back(0);

    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
  }
};
