#include<bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, long long> tree;
  vector<pair<long long, long long>> ans;
  tree[n] = 1;
  long long cur = n;
  while (cur > 0) {
    auto it = (--tree.end());
    cur = it-> first;
    long long frec = it-> second;
    tree.erase(it);
    ans.emplace_back(frec, cur);
    if (cur <= 1) break;
    long long tmp = cur - 1;
    long long a = tmp >> 1;
    long long b = tmp - a;
    tree[a] += frec;
    tree[b] += frec;
  }

  long long acc = 0;
  for (auto i : ans) {
    acc += i.first;
    if (acc >= k) {
      long long tmp = i.second - 1;
      long long a = tmp >> 1;
      printf("%lld %lld\n", tmp - a, a);
      return;
    }
    // printf("%lld with len %lld\n", i.first, i.second);
  }
  assert(acc == n);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
