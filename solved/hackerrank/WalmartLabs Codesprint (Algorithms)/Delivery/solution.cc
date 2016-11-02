#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

const int MF = 12345;
const int MN = 1e5 + 100;

vector<int> food[MF];
int level[MN];

long long get_cost(int a, int b) {
  if (a == b) return 0;
  if (level[a] == level[b]) return 2 + get_cost(a >> 1, b >> 1);
  if (level[a] > level[b]) return 1 + get_cost(a >> 1, b);
  return 1 + get_cost(a, b >> 1);
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  level[1] = 1;
  for (int i = 1; i < MN; ++i) {
    int a = i << 1, b = i << 1 | 1;
    if (a < MN) level[a] = level[i] + 1;
    if (b < MN) level[b] = level[i] + 1;
  }

  int n, m,  q;
  while (cin >> n >> m >> q) {
    for (int i = 0; i < m; ++i) {
      int t; cin >> t;
      food[i + 1].resize(t);
      for (int j = 0; j < t; ++j)
        cin >> food[i + 1][j];
    }

    int node = 1;
    int type, end;
    long long total = 0;
    for (int i = 0; i < q; ++i) {
      cin >> type >> end;
      long long cur = 1LL << 50;
      for (int j = 0; j < (int)food[type].size(); ++j) {
        int to = food[type][j];
        cur = min(cur, get_cost(node, to) + get_cost(to, end));
      }
      total += cur;
      node = end;
    }
    cout << total << endl;
  }
  return 0;
}
