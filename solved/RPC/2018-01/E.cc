#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif

struct data{
  int a, b, c;
  data() {}
  data(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n, m;
  while (cin >> n >> m) {
    vector<int> ans(n);
    vector<bool> used(m);
    vector<pair<int,int>> cap(n);
    vector<data> buildings(m);
    int it = 0;
    for (auto &i : cap) {
      cin >> i.first;
      i.second = it++;
    }
    for (auto &i : buildings) {
      cin >> i.a;
    }
    it = 0;
    for (auto &i : buildings) {
      cin >> i.b;
      i.c = it++;
    }
    sort(cap.rbegin(), cap.rend());
    sort(buildings.begin(), buildings.end(),
      [](const data &a, const data &b) {
        if (a.a == b.a) {
          if (a.b == b.b) return a.c < b.c;
          return a.b < b.b;
        }
        return a.a > b.a;
      }
    );
    // for (auto i : cap) cout << i.first << " "; cout << endl;
    // for (auto i : buildings) cout << i.a << " " << i.b << " " << i.c << endl;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int anst = 1000000, val = -1;
      bool found = false;
      for (int j = 0; j < m; j++) {
        if (used[buildings[j].c]) continue;
        if (buildings[j].a < cap[i].first) break;
        if (buildings[j].b < anst) {
          anst = buildings[j].b;
          val = buildings[j].c;
          found = true;
        }
      }
      if (!found) { ok = false; break; }
      //cout << anst << endl;
      used[val] = true;
      ans[cap[i].second] = val + 1;
    }
    if (!ok) cout << "impossible" << endl;
    else {
      for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
      }
      cout << endl;

    }

  }

  return 0;
}
