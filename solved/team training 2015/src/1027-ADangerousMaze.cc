#include <bits/stdc++.h>
using namespace std;

string ltos(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

string solve() {
  int n; cin >> n;
  long long N = 0;

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long e; cin >> e;
    sum += abs(e);
    if (e < 0)
      N++;
  }

  if (N == n)
    return "inf";

  long long den = n - N, g = __gcd(sum, den);
  return ltos(sum / g) + "/" + ltos(den / g);
}

int main() {
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    cout << "Case " << i + 1 << ": " << solve() << endl;

  return 0;
}
