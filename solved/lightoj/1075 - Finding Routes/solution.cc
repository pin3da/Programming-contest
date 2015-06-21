using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  int n;
  cin >> n;
  map<string, int> names;
  map<int, string> inv;
  string u, v;
  int id = 0;
  vector<int> next(n, -1), prev(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    if (names.count(u) == 0) {
      names[u] = id;
      inv[id++] = u;
    }
    if (names.count(v) == 0) {
      names[v] = id;
      inv[id++] = v;
    }
    int uu = names[u], vv = names[v];
    next[uu] = vv;
    prev[vv] = uu;
  }
  for (int i = 0; i < n; ++i)
    if (prev[i] == -1) {
      while (next[i] != -1) {
        printf("%s\n", inv[i].c_str());
        i = next[i];
      }
      printf("%s\n", inv[i].c_str());
      break;
    }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
    puts("");
  }

  return 0;
}
