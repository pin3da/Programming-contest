#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int N = 10000000 + 1000;  // limit for array size

struct segtree {
  int n;  // array size
  int t[2 * N];

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  // Single modification, range query.
  void add(int p, int value) {  // add value at position p
    for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};


namespace primes {
  const int MP = 1000001 + 100;
  bool sieve[MP];
  long long primes[MP];
  int num_p;
  void fill_sieve() {
    num_p = 0;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i < MP; ++i) {
      if (!sieve[i]) {
        primes[num_p++] = i;
        for (long long j = i * i; j < MP; j += i)
          sieve[j] = true;
      }
    }
  }

  vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ans;
    if (n == 0) return ans;
    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
      if ((n % primes[i]) == 0) {
        int expo = 0;
        while ((n % primes[i]) == 0) {
          expo++;
          n /= primes[i];
        }
        ans.emplace_back(primes[i], expo);
      }
    }

    if (n > 1) {
      ans.emplace_back(n, 1);
    }
    return ans;
  }
}


struct event {
  int q_id, pri, mult;
  event() {}
  event(int a, int b, int c) : q_id(a), pri(b), mult(c) {}
};
segtree tree;

void solve() {
  int n; cin >> n;
  vector<int> all(n + 1);
  for (int i = 0; i < n; ++i)
    cin >> all[i + 1];

  vector<vector<event>> events(n + 1);
  int q; cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    events[r].emplace_back(i, y, 1);
    events[r].emplace_back(i, x - 1, -1);
    events[l - 1].emplace_back(i, y, -1);
    events[l - 1].emplace_back(i, x - 1, 1);
  }

  memset(tree.t, 0, sizeof tree.t);
  tree.n = 1e6 + 10;
  vector<int> ans(q);

  for (int i = 0; i < n + 1; ++i) {
    vector<pair<int, int>> data = primes::factor(all[i]);
    for (auto it : data)
      tree.add(it.first, it.second);

    for (auto ev : events[i])
      ans[ev.q_id] += tree.query(0, ev.pri + 1) * ev.mult;
  }

  for (int it : ans) {
    cout << it << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  primes::fill_sieve();
  solve();
  return 0;
}
