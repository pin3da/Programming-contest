#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> all(n);
  for (int &i : all) cin >> i;
  sort(all.begin(), all.end());
  int ans = 0;
  do {
    int rem = 0;
    int acc = 0;
    for (int i = 0; i < n; ++i) {
      acc += (rem == 0);
      rem = (rem + all[i]) % p;
    }
    ans = max(ans, acc);
  } while (next_permutation(all.begin(), all.end()));
  printf("%d\n", ans);
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
