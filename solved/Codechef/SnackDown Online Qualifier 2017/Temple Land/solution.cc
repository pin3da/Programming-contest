#include <bits/stdc++.h>

using namespace std;

int main() {
  int s; cin >> s;
  while (s--) {
    int n; cin >> n;
    vector<int> all(n);
    for (int &i : all) cin >> i;
    int ok = all.size() & 1;
    int mid = all.size() >> 1;
    ok &= (all[0] == 1);
    ok &= (all[n - 1] == 1);
    for (int i = 1; i < mid; ++i)
      ok &= (all[i - 1] + 1) == all[i];
    for (int i = mid + 1; i + 1 < n; ++i)
      ok &= (all[i + 1] + 1) == all[i];
    puts(ok ? "yes" : "no");
  }
  return 0;
}
