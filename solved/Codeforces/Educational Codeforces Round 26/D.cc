#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct factor {
  int five, two, m;
  factor() {}
  factor(int a, int b) : five(a), two(b), m(min(a, b)) {}
};


const int MN = 201;
factor dp[2][MN];

factor choose(factor &a, factor &b) {
  if (a.m > b.m) return a;
  if (a.m < b.m) return b;
  if (max(a.five, a.two) > max(b.five, b.two)) return a;
  return b;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, K;
  cin >> n >> K;
  vector<factor> all;
  for (int i = 0; i < n; i++) {
    long long t; cin >> t;
    int f = 0, two = 0;
    while ((t % 5) == 0) {
      f++;
      t /= 5;
    }
    while ((t % 2) == 0) {
      two++;
      t /= 2;
    }
    all.emplace_back(f, two);
  }

  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int k = 1; k < MN; k++) {
      factor next(dp[cur ^ 1][k - 1].five + all[i].five,
                  dp[cur ^ 1][k - 1].two + all[i].two);
      dp[cur][k] = choose(dp[cur ^ 1][k], next);
    }
    cur ^= 1;
  }

  cout << dp[cur ^ 1][K].m << endl;
  return 0;
}
