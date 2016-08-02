#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

typedef unsigned long long ull;

ull one = 0;
const ull mmax = one - 1;
const int MN = 93;

ull fib[MN];
set<ull> sons;


const int N = 234567;  // limit for array size
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

  fib[0] = fib[1] = 1;
  for (int i = 2; i < MN; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    assert(fib[i] > fib[i - 1]);
  }

  //for(int i = 0; i < MN; i++) cout << fib[i] << endl;
  for (int i = 1; i < MN; ++i) {
    for (int j = i + 1; j < MN; ++j) {
      if (fib[j] <= mmax - fib[i])
        sons.insert(fib[i] + fib[j]);
    }
  }

  assert(sons.count(7) == 1);
  assert(sons.count(12) == 0);
  assert(sons.count(17) == 0);

  int q;
  while (cin >> n >> q) {
    memset(t, 0, sizeof t);
    for (int i = 0; i < n; ++i) {
      ull tmp; cin >> tmp;
      t[i + n] = sons.count(tmp);
    }

    build();

    for (int i = 0; i < q; ++i) {
      ull type, u;
      ull v; cin >> type >> u >> v;
      if (type == 1) {
        if (u > v) swap(u, v);
        u--;
        cout << query(u, v) << endl;
      } else {
        u--;
        modify(u, sons.count(v));
      }
    }
  }
  return 0;
}
