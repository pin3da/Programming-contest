#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool test(char a, char b, vector<int> &bad) {
  if (a == '?') return !bad[b - 'a'];
  return a == b;
}

bool check(string &line, string &pattern, vector<int> &bad) {
  if (pattern.find("*") == string::npos) {
    int ok = true;
    if (pattern.size() != line.size()) return false;
    for (int i = 0; i < (int)line.size(); ++i) {
      ok &= test(pattern[i], line[i], bad);
    }
    return ok;
  }

  if (line.size() < (pattern.size() - 1)) return false;
  int id = pattern.find("*");
  int ok = true;
  for (int i = 0; i < id; ++i) ok &= test(pattern[i], line[i], bad);
  int len = pattern.size() - id - 1;
  int last = line.size() - 1 - len;
  for (int i = 0; i < len; ++i)
    ok &= test(pattern[pattern.size() - i - 1], line[line.size() - i - 1], bad);

  for (int i = id; i <= last; ++i) {
    ok &= bad[line[i] - 'a'];
  }
  return ok;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string good;
  cin >> good;
  vector<int> bad(30, 1);
  for (auto i : good) bad[i - 'a'] = 0;

  string pattern;
  cin >> pattern;

  int q; cin >> q;
  while (q--) {
    string line; cin >> line;
    int ok = (check(line, pattern, bad));
    puts(ok? "YES" : "NO");
  }

  return 0;
}
