#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
long double p;

long double f(int n) {
  if (n == 0) return 1.0;

  long double ans = 0.0;
  long double k = 1.0 / (2.0 * f(n - 1));
  if (k < p)
    ans = f(n - 1) * (1.0 - p * p);
  else
    ans = (k - p) + (1.0 - k * k) * f(n - 1);

  return ans / (1.0 - p);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(2);
  while (cin >> N >> p && (N > 0)) {
    cout << f(N) + 1e-9 << endl;
  }
  return 0;
}
