#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;

const int inf = 3600 * 3600 + 10;

int safe(int x) {
  return max(0, min(x, 3600));
}

int T;
pair<int, int> fill_dp(vector<int> &a) {
  queue<int> q;
  vector<int> dist(3601, inf);
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    if (dist[cur] < inf) {
      for (int i = 0; i < a.size(); ++i) {
        int nd = dist[cur] + 1;
        if (nd < dist[safe(cur + a[i])]) {
          dist[safe(cur + a[i])] = nd;
          q.push(safe(cur + a[i]));
        }
      }
    }
  }
  
  for (int i = T; i < 3601; ++i) {
    if (dist[i] < inf) {
      return make_pair(dist[i], i - T);
    }
  }
}

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  
  T = t;

  pair<int, int> ans = fill_dp(a);  
  cout << ans.first << " " << ans.second << endl;
}

int main() {
 srand(time(0));
 int tc; cin >> tc;
 for (int i = 0; i < tc; ++i) {
  solve();
 }
 return 0;
}
