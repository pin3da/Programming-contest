#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> a(3);
  for (int i = 0; i < 3; i++) cin >> a[i];
  long long best = 10000000LL;
  for (int i = 0; i < 3; i++) {
    long long cur = 0;
    for (int j = 0; j < 3; j++) {
      cur += abs(i - j) * a[j] * 2;
    }
    best = min(best, cur);
  }

  cout << best << endl;
  return 0;
}
