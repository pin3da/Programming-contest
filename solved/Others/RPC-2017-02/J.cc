using namespace std;
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

const long long inf = 1e18 + 100;
const int SQ = 1000;

int n;
long long arr[212345];
long long min_b[SQ + 100];

void build() {
  for (int i = 0; i < SQ; ++i)
    min_b[i] = inf;
  for (int i = 0; i < n; ++i) {
    int bucket = i / SQ;
    min_b[bucket] = min(min_b[bucket], arr[i]);
  }
}

int query_bucket(long long x, int i) {
  int start = i;
  int end = min(start + SQ, n);
  for (i; i < end; ++i) {
    if (arr[i] <= x)
      return i;
  }
  return n;
}

int query(long long x, int i) { // leftmost lower than or equals to x, starting at i
  int ans = query_bucket(x, i);
  if (ans < n)
    return ans;

  int start = i / SQ + 1;
  int end = min(n / SQ, SQ - 1);
  for (int b = start; b <= end; ++b) {
    if (min_b[b] <= x)
      return query_bucket(x, b * SQ);
  }
  return n;
}


int main() {
  int q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  build();

  while (q--) {
    long long have; cin >> have;
    int l, r; cin >> l >> r;
    l--;r--;
    while (l <= r && l < n) {
      have %= arr[l];
      if (l == n - 1) break;
      l = query(have, l + 1);
      assert(l <= n);
    }
    cout << have << endl;
  }
  return 0;
}
