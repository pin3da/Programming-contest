#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> all(n);
  vector<int> frec(p);
  for (int &i : all) {
    cin >> i;
    frec[i % p]++;
  }
  int ans = 0;
  if (p == 2) {
    ans = frec[0];
    ans += frec[1] / 2;
    ans += frec[1] % 2;
  }
  if (p == 3) {
    ans = frec[0];
    int t = min(frec[1], frec[2]);
    frec[1] -= t;
    frec[2] -= t;
    ans += t;
    ans += frec[1] / 3;
    ans += frec[2] / 3;
    ans += ((frec[1] + frec[2]) % 3) != 0;
  }

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
