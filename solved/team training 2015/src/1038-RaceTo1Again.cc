#include <bits/stdc++.h>
using namespace std;

const int MN = 100010;
double dp[MN];

double E(int d) {
  if (dp[d] > -0.5)
    return dp[d];

  if (d == 1)
    return 0;

  int nD = 2, i;
  double ans = 2; // divide by itself and the 1 in (1 + E(d)) (dividing by 1)
  for (i = 2; i * i < d; i++)
    if (d % i == 0) {
      nD += 2;
      ans += (1 + E(i)); // d / (d / i)
      ans += (1 + E(d / i));
    }
  if (i * i == d) {
    nD++;
    ans += (1 + E(d / i));
  }

  return dp[d] = ans / (nD - 1); // (ans / nD) / (1 - 1/nD)
}


int main() {
  for (int i = 0; i < MN; i++)
    dp[i] = -1;
  dp[1] = 0;
  for (int i = 2; i < MN; i++)
    E(i);
  
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n; cin >> n;
    cout << "Case " << i + 1 << ": " << fixed << setprecision(10) << dp[n] << endl;
  }
  
  return 0;
}
