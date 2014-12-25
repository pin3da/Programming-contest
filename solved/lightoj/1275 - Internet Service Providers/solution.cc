using namespace std;
#include <bits/stdc++.h>

long long f(long long t, long long n, long long c) {
  return t * (c - n * t);
}

void solve() {
  int n, c;
  cin >> n >> c;
  if (n == 0) {
    cout << 0 << endl;
    return;
  }
  int t1 = (c / (2 * n)),
      t2 = (c / (2 * n)) + 1;

  if (f(t1, n, c) >= f(t2, n, c)) {
    cout << t1 << endl;
  } else {
    cout << t2 << endl;
  }

}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cout << "Case " << (i + 1) << ": ";
    solve();
  }

  return 0;
}
