using namespace std;
#include <bits/stdc++.h>


const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

// Single modification, range query.
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


void solve() {
  int q;
  cin >> n >> q;
  memset(t, 0, sizeof t);
  for (int i = 0; i < n; ++i)
    cin >> t[n + i];

  build();
  int op, a, b;
  while (q--) {
    cin >> op >> a;
    if (op == 1) {
      printf("%d\n", query(a, a + 1));
      modify(a, 0);
    } else if (op == 2) {
      cin >> b;
      modify(a, query(a, a + 1) +b);
    } else {
      cin >> b;
      printf("%d\n", query(a, b + 1));
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n",i + 1);
    solve();
  }
  return 0;
}
