#include <bits/stdc++.h>

#define debug(x) cerr << #x " = " << (x) << endl

using namespace std;

long double fun(long double v, long double w) {
  return log(1.0 + v / w);
}

int main() {
  int n;
  long double w;
  cin >> n >> w;
  vector<long double> dp(n + 1), v(n + 1), p(n + 1);
  vector<int> last_safe(n + 1), safe(n + 1);

  for (int i = 1; i <= n; ++i) {
    string t; cin >> t;
    safe[i] = t == "safe";
    cin >> p[i] >> v[i];
    v[i] = fun(v[i], w);
  }

  for (int i = 0; i < n; ++i) {
    if (safe[i]) last_safe[i + 1] = i;
    else         last_safe[i + 1] = last_safe[i];
  }

  long double pcc = 1.0;
  long double acc = 0;
  for (int i = 1; i <= n; ++i) {
    acc += pcc * (1.0 - p[i]) * v[last_safe[i]];
    long double cur = pcc * p[i] * v[i] + acc;
    dp[i] = max(dp[i - 1], cur);
    pcc *= p[i];
  }

  long double ans = (exp(dp[n]) - 1) * w;
  cout << fixed << setprecision(2);
  cout << "$" << ans << endl;
  return 0;
}
