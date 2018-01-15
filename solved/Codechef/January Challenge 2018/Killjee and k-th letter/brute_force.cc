#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  string s; cin >> s;
  vector<string> data;

  int len = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    string cur;
    for (int j = 1; i + j <= (int) s.size(); j++) {
      cur.push_back(s[i + j - 1]);
      data.push_back(cur);
      len += cur.size();
    }
  }

  sort(data.begin(), data.end());

 // debug(len);
  /*
  for (auto it : data)
    debug(it);
  */

  long long g = 0;
  int q; cin >> q;
  while (q--) {
    long long p, m; cin >> p >> m;
    int k = (g * p) % m;
   // debug(k);
    for (int i = 0; i < (int) data.size(); i++) {
      if ((int) data[i].size() > k) {
        cout << data[i][k] << endl;
        g += data[i][k];
        break;
      } else {
        k -= data[i].size();
      }
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
