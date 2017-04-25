// http://codeforces.com/contest/730/problem/H

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool find_pattern(vector<string> &a, string &p) {
  size_t len = a[0].size();
  for (int i = 0; i < (int)a.size(); ++i) {
    if (len != a[i].size()) return false;
  }

  for (int i = 0; i < (int)len; ++i) {
    int same = 1;
    for (int j = 0; j < (int)a.size(); ++j) {
      same &= (a[j][i] == a[0][i]);
    }
    if (same) p.push_back(a[0][i]);
    else p.push_back('?');
  }
  return true;
}


bool match_any(vector<string> &a, string p) {
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i].size() != p.size()) continue;
    int ok = true;
    for (int j = 0; j < (int)p.size(); ++j) {
      if ((p[j] == '?') || a[i][j] == p[j]) continue;
      ok = false;
      break;
    }
    if (ok) return true;
  }
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m;
  while (cin >> n >> m) {
    vector<string> all(n);
    for (int i = 0; i < n; ++i)
      cin >> all[i];

    vector<int> t(n);
    for (int i = 0; i < m; ++i) {
      int w; cin >> w;
      t[w - 1] = 1;
    }

    vector<string> a, b;
    for (int i = 0; i < n; ++i) {
      if (t[i]) a.push_back(all[i]);
      else b.push_back(all[i]);
    }
    string pattern;
    if (find_pattern(a, pattern)) {
      if (match_any(b, pattern)) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl << pattern << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
