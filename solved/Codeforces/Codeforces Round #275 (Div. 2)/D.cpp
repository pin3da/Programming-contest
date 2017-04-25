// http://codeforces.com/contest/483/problem/D

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  int n, m;
  cin >> n >> m;

  map<int, vector<int> > open, close;
  vector<pair<pair<int, int>, int> > query(m);
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    a--;b--;
    query[i].first.first = a;
    query[i].first.second = b;
    query[i].second = c;
    open[a].push_back(c);
    close[b].push_back(c);
  }

  vector<int> ans(n, 0);
  vector<int> mask(30, 0);
  int current = 0;

  for (int i = 0; i < n; ++i) {
    if (open.count(i)) {
      vector<int> &op = open[i];
      for (int j = 0; j < op.size(); ++j) {
        int cur = op[j];
        for (int k = 0; k < 30; ++k) {
          if ((cur >> k) & 1)
            mask[k]++;
        }
      }
    }

    for (int k = 0; k < 30; ++k) {
      if(mask[k] > 0)
        ans[i] |= (1 << k);
    }

    if (close.count(i)) {
      vector<int> &cl = close[i];
      for (int j = 0; j < cl.size(); ++j) {
        int cur = cl[j];
        for (int k = 0; k < 30; ++k) {
          if ((cur >> k) & 1)
            mask[k]--;
        }
      }
    }
  }

  int possible = 1;
  vector<vector<int> > ps(30, vector<int>(n, 0));

  for (int k = 0; k < 30; ++k)
    if (((ans[0] >> k) & 1) == 0)
      ps[k][0] = 1;

  for (int k = 0; k < 30; ++k) {
    for (int i = 1; i < n; ++i) {
      if (((ans[i] >> k) & 1) == 0)
        ps[k][i] = 1;
      ps[k][i] += ps[k][i - 1];
    }
  }

  /*for (int k = 0; k < 30; ++k) {
    for (int i = 0; i < n; ++i)
      cout << ps[k][i] << " ";
    cout << endl;
  }*/

  for (int i = 0; i < m; ++i) {
    int x = query[i].first.first;
    int y = query[i].first.second;
    int z = query[i].second;
    int tmp = 0;
    for (int k = 0; k < 30; ++k) {
      int zero = ps[k][y];
      if (x)
        zero -= ps[k][x - 1];
      if (zero == 0)
        tmp |= (1 << k);
    }
    // cout << i << " " << tmp << endl;
    possible = possible and (tmp == z);
  }


  if (possible) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}