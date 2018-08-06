#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Parser {
  string input;
  size_t pos;
  Parser(const string &c) : input(c), pos(0) {}

  string ParseElement() {
    string result;
    result.push_back(input[pos]);
    pos++;
    while (pos < input.size() && islower(input[pos])) {
      result.push_back(input[pos]);
      pos++;
    }
    return result;
  }

  int ParseFrec() {
    if (pos >= input.size()) return 1;
    if (!isdigit(input[pos])) return 1;
    int result = 0;
    while (pos < input.size() && isdigit(input[pos])) {
      result *= 10;
      result += input[pos] - '0';
      pos++;
    }
    return result;
  }

  map<string, int> Parse() {
    map<string, int> result;
    while (pos < input.size() && input[pos] != ')') {
      if (isupper(input[pos])) {
        string elem = ParseElement();
        int frec = ParseFrec();
        result[elem] += frec;
      } else if (input[pos] == '(') {
        pos++; // '('
        auto tmp = Parse();
        pos++; // ')'
        int frec = ParseFrec();
        for (auto &it : tmp) {
          result[it.first] += it.second * frec;
        }
      }
      auto tmp = Parse();
      for (auto it : tmp) result[it.first] += it.second;
    }
    return result;
  }
};

class Solution {
  public:
    string countOfAtoms(string formula) {
      Parser parser(formula);
      auto result = parser.Parse();
      string count;
      for (auto it : result) {
        count += it.first;
        if (it.second > 1) count += to_string(it.second);
      }
      return count;
    }
};

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  Solution sol;
  cout << sol.countOfAtoms("H2O") << endl;
  cout << sol.countOfAtoms("Mg(OH)2") << endl;
  cout << sol.countOfAtoms("K4(ON(SO3)2)2") << endl;

  return 0;
}
