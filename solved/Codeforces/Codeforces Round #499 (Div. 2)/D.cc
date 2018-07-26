#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> is_true(n);
  for (int i = 0; i < n; i++) {
    cout << m << endl;
    cin >> is_true[i];
    if (is_true[i] == 0) {
      return 0;
    }
  }

  int lo = 1, hi = m - 1;
  int p = 0, ans;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    cout << mid << endl;
    cin >> ans;

    if (ans == 0) {
      return 0;
    }

    ans *= is_true[p];
    if (ans == -1) lo = mid + 1;
    else hi = mid - 1;

    p = (p + 1) % n;
  }

  cout << lo << endl;
  cin >> ans;
  assert(ans == 0);
  return 0;
}
