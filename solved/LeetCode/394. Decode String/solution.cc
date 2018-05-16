#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

class Solution {

  vector<int> findMatches(string &s) {
    stack<int> st;
    vector<int> ans(s.size(), -1);
    for (int i = 0; i < int(s.size()); i++) {
      if (s[i] == '[') {
        st.push(i);
      } else if (s[i] == ']') {
        int c = st.top();
        ans[c] = i;
        ans[i] = c;
        st.pop();
      }
    }
    return ans;
  }

  string parse(string &s, vector<int> &matches, int begin, int end) {
    if (begin > end)
      return string();
    if (begin == end) {
      string ans; ans.push_back(s[begin]);
      return ans;
    }

    if (isdigit(s[begin])) { // group;
      int times = 0;
      while (isdigit(s[begin])) {
        times *= 10;
        times += s[begin] - '0';
        begin++;
      }

      string result = parse(s, matches, begin + 1, matches[begin] - 1);

      string answer;
      for (int i = 0; i < times; i++) {
        for (auto c : result)
          answer.push_back(c);
      }

      string right = parse(s, matches, matches[begin] + 1, end);
      for (auto c : right) {
        answer.push_back(c);
      }
      return answer;
    } else { // string
      string answer;
      while (!isdigit(s[begin]) && begin <= end) {
        answer.push_back(s[begin]);
        begin++;
      }
      for (auto c : parse(s, matches, begin, end))
        answer.push_back(c);
      return answer;
    }

  }

  public:
  string decodeString(string s) {
    vector<int> matches = findMatches(s);
    string ans = parse(s, matches, 0, s.size() - 1);
    return ans;
  }
};
