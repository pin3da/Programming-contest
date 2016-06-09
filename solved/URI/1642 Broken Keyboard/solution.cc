#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool f(const string &line, int len, int n) {
  unordered_map<char, int> s;
  for (int i = 0; i < len; ++i)
    s[line[i]]++;

  if (s.size() <= n) return true;
  for (int i = len; i < line.size(); ++i) {
    s[line[i]]++;
    s[line[i - len]]--;
    if (s[line[i - len]] == 0) s.erase(line[i - len]);
    if (s.size() <= n) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  string line;
  while (getline(cin, line) && line != "0") {
    n = stoi(line);
    getline(cin, line);
    int lo = 1, hi = line.size();
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (f(line, mid, n))
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << endl;
  }

  return 0;
}

