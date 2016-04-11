#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

void solve() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << "INSOMNIA" << endl;
    return;
  }

  long long ans = 0;
  set<int> seen;
  for (long long i = 1; seen.size() < 10; ++i) {
    long long cur = n * i;
    ans = cur;
    while (cur > 0) {
      seen.insert(cur % 10);
      cur /= 10;
    }

  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
