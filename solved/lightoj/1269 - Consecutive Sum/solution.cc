using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 50005 * 33;
struct trie{
  int t[MN][2];
  int nodes;
  void clear() {
    memset(t, -1, sizeof t);
    nodes = 1;
  }

  void add(int mask) {
    int cur = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] == -1) {
        t[cur][next] = nodes;
        nodes++;
      }
      cur = t[cur][next];
    }
  }

  int get_min(int mask) {
    int cur = 0, ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] != -1) {
        ans <<= 1;
        cur = t[cur][next];
      } else {
        cur = t[cur][next ^ 1];
        ans <<= 1;
        ans++;
      }
    }
    return ans;
  }

  int get_max(int mask) {
    int cur = 0, ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = ((mask >> i) & 1) ^ 1;
      if (t[cur][next] != -1) {
        ans <<= 1;
        ans++;
        cur = t[cur][next];
      } else {
        cur = t[cur][next ^ 1];
        ans <<= 1;
      }
    }
    return ans;
  }
};

trie tree;

void solve() {
  int n, t;
  cin >> n;
  tree.clear();
  int cur = 0;
  tree.add(cur);
  int mmin, mmax;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (i == 0) {
      mmin = t;
      mmax = t;
    }
    cur ^= t;
    mmin = min(mmin, tree.get_min(cur));
    mmax = max(mmax, tree.get_max(cur));
    tree.add(cur);
  }
  printf("%d %d\n", mmax, mmin);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
