#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2 * 100000 + 100;

int to[MN], can[MN], inc[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    memset(inc, 0, sizeof inc);
    memset(can, 0, sizeof can);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> to[i];
      to[i]--;
      inc[to[i]]++;
    }
    deque<int> q;
    for (int i = 0; i < 2 * n; ++i) {
      if (inc[i] == 0) q.push_back(i);
    }

    while (!q.empty()) {
      int cur = q.front(); q.pop_front();
      can[cur] = 1;
      if (can[to[cur]] == -1) continue;
      can[to[cur]] = -1;
      int next = to[to[cur]];
      inc[next]--;
      if (inc[next] == 0) q.push_back(next);
    }

    // remaining nodes must form a simple cycle with even length

    for (int i = n; i < 2 * n; ++i) {
      if (can[i] == 0)
        can[i] = -1;
    }

    for (int i = 0; i < 2 * n; ++i) {
      if (can[i] != -1)
        cout << i + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
