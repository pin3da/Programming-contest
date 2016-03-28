#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> t[n + i];

  build();
  char op;
  int val;
  while (cin >> op >> val) {
    val--;
    if (op == 'a')
      modify(val, 0);
    else
      cout << query(0, val) << endl;
  }
  return 0;
}
