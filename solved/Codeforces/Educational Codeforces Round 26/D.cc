#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct factor {
  int five, two, m;
  factor() {}
  factor(int a, int b) : five(a), two(b), m(min(a, b)) {}
};


const int MN = 201;
const int MF = 100;
const int MT = 100;
int dp[2][MN][MF][MT];

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
      for (int f = 0; f < MF; f++) {
        for (int t = 0; t < MT; t++) {
          if (k == 1) {
            dp[cur][k][f][t] = max(
                dp[cur ^ 1][k][f][t],
                min(f + all[i].five, t + all[i].two)
            );
          } else {
            dp[cur][k][f][t] = max(
                dp[cur ^ 1][k][f][t],
                dp[cur ^ 1][k - 1][f + all[i].five][t + all[i].two]
            );
          }
        }
      }
    }
    cur ^= 1;
  }

  cout << dp[cur ^ 1][K][0][0] << endl;
  return 0;
}
