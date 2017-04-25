// http://codeforces.com/contest/639/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, q, k;
  while (cin >> n >> k >> q) {
    vector<int> t(n);
    for (auto &i : t) cin >> i;
    deque<pair<int, int>> online;
    while (q--) {
      int type, id;
      cin >> type >> id;
      if (type == 1) {
        online.emplace_back(t[id - 1], id - 1);
        sort(online.rbegin(), online.rend());
        while (online.size() > k) online.pop_back();
      } else {
        int seen = false;
        for (auto &i : online)
          seen |= (i.second + 1 == id);
        if (seen)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }

  return 0;
}
