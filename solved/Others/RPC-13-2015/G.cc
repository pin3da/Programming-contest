using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


void solve(int n) {
  map<int, map<int, int>> p;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    p[x][y]++;
  }
  
  int m, r;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> r;
    
    map<int, map<int, int> >::iterator it = p.lower_bound(x - r);
    for (; it != p.end() && it->first <= x + r; ++it) {
      map<int, int>::iterator ss = it-> second.lower_bound(y - r);
      while (ss != it->second.end() && ss->first <= y + r) {
        int nx = it-> first - x;
        int ny = ss-> first - y;
        if (nx * nx + ny * ny <= r * r)
          ss = it->second.erase(ss);
        else
          ss++;
      }
    }
  }
  
  int ans = 0;
  for (auto &i: p) {
    for (auto &j: i.second) 
      ans += j.second;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}

