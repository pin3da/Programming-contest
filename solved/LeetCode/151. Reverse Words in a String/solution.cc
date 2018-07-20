class Solution {
  public:
    void reverseWords(string &s) {
      stringstream ss(s);
      string ans, tmp;
      ss >> ans;
      while (ss >> tmp) ans = tmp + " " + ans;
      s = ans;
    }
};
