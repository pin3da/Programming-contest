#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MAX_K = 2511;

typedef bitset<MAX_K> mask;

struct trie {
  int t[MAX_K * MAX_K + 100][2];
  int frec[MAX_K * MAX_K];
  int id;

  void init(int node = 0) {
    if (node == 0) id = 1;
    memset(t[node], -1, sizeof t[node]);
    frec[node] = 0;
  }

  void add(mask cur, int len) {
    int node = 0;
    for (int i = len - 1; i >= 0; --i) {
      int to = t[node][cur[i]];
      if (to == -1) {
        init(id);
        t[node][cur[i]] = id;
        id++;
      }
      node = t[node][cur[i]];
    }
    frec[node]++;
  }

  int query(mask cur, int node, int len) {
    if (len == 0) return frec[node];
    int to = cur[len - 1];
    if (to == 0) {
      if (t[node][1] == -1) return 0;
      return query(cur, t[node][1], len - 1);
    }
    int ans = 0;
    if (t[node][0] != -1) ans += query(cur, t[node][0], len - 1);
    if (t[node][1] != -1) ans += query(cur, t[node][1], len - 1);
    return ans;
  }
};

trie tree;

void solve() {
  int n, k; cin >> n >> k;
  int ans = 0;
  tree.init();
  for (int i = 0; i < n; ++i) {
    int len; cin >> len;
    mask current;
    for (int j = 0; j < len; ++j) {
      int tmp; cin >> tmp;
      current.set(tmp - 1, 1);
    }
    ans += tree.query(current, 0, k);
    tree.add(current, k);
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }

  return 0;
}
