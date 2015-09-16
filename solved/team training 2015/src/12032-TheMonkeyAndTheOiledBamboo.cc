#include <bits/stdc++.h>
using namespace std;

bool can(int r[], int n, int k) {
  for (int i = 1; i < n; i++) {
    int jump = r[i] - r[i - 1];
    if (jump > k)
      return false;

    if (jump == k)
      k--;
  }
  return true;
}

int solve(int r[], int n, int maxx) { // [F, T]
  int lo = 0, hi = maxx;
  while (hi - lo > 1) {
    int mid = (hi + lo) >> 1;
    if (can(r, n, mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  int tc; cin >> tc;
  for (int c = 0; c < tc; c++) {
    int n; cin >> n;
    n++;
    int r[n], maxx = -1;
    r[0] = 0;
    for (int i = 1; i < n; i++) {
      cin >> r[i];
      maxx = max(maxx, r[i]);
    }

    
    cout << "Case " << c + 1 << ": " << solve(r, n, maxx + n) << endl;
  }
  
  return 0;
}
