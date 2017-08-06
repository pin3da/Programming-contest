#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> in(n);
  vector<int> out(n);
  vector<int> stay(n, 1);

  int m, x, l;
  cin >> m >> x >> l;
  x--; l--;

  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    in[a]++;
    in[b]++;
  }

  deque<int> leave;
  leave.push_back(l);
  stay[l] = false;
  while (!leave.empty()) {
    int cur = leave.front();
    if (cur == x) break;
    leave.pop_front();
    for (int to : g[cur]) {
      if (stay[to]) {
        out[to]++;
        if (out[to] >= ((in[to] + 1) / 2)) {
          leave.push_back(to);
          stay[to] = false;
        }
      }
    }
  }

  puts(stay[x] ? "stay" : "leave");

  return 0;
}
