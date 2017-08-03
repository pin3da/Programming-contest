#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int fs(vector<int> &p, int x) {
  return x == p[x] ? x : p[x] = fs(p, p[x]);
}
void js(vector<int> &p, int x, int y) {
  p[fs(p, x)] = fs(p, y);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, a, b;
  cin >> n >> a >> b;
  map<int, int> pos;
  vector<int> data(n);
  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    data[i] = t;
    pos[t] = i;
    p[i] = i;
  }

  int ok = true;
  int root_a = -1;
  int root_b = -1;
  for (int i = 0; i < n; i++) {
    if (pos.count(a - data[i])) {
      js(p, i, pos[a - data[i]]);
      root_a = i;
    } else if (pos.count(b - data[i])) {
      js(p, i, pos[b - data[i]]);
      root_b = i;
    } else {
      ok = false;
    }
  }

  vector<int> ans(n);
  if (root_a != -1) {
    root_a = fs(p, root_a);
    for (int i = 0; i < n; i++) {
      if (fs(p, i) == root_a) ans[i] = 1;
    }
  }
  if (root_b != -1) {
    root_b = fs(p, root_b);
    for (int i = 0; i < n; i++) {
      if (fs(p, i) == root_b) {
        if (ans[i] == 1) ok = false;
        else ans[i] = 2;
      }
    }
  }

  if (ok) {
    cout << "YES" << endl;

    for (int i = 0; i < n; ++i) {
      cout << ans[i] - 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
