// http://codeforces.com/contest/513/problem/G1

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

long double go(vector<int> &p, int k) {
  if (k == 0) {
    long double ans = 0;
    for (int i = 0; i < p.size(); ++i)
      for (int j = i + 1; j < p.size(); ++j)
        if (p[j] < p[i]) ans++;
    return ans;
  }

  long double ans = 0;
  long double den = 0;

  for (int i = 0; i < p.size(); ++i)
    for (int j = i; j < p.size(); ++j)
      den += 1;

  for (int i = 0; i < p.size(); ++i) {
    for (int j = i; j < p.size(); ++j) {
      reverse(p.begin() + i, p.begin() + j + 1);
      ans += go(p, k - 1) / den;
      reverse(p.begin() + i, p.begin() + j + 1);
    }
  }

  return ans;
}

int main() { ___

  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  // printf("%.15lf\n", go(p, k) + 1e-14);
  cout << fixed << setprecision(15) << go(p, k) + 1e-14 << endl;


  return 0;
}
