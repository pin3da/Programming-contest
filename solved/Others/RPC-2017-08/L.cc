#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());

  int ok = false;
  for (int i = 2; i < n; i++) {
    if (a[i - 2] + a[i - 1] > a[i])
      ok = true;
  }
  puts(ok ? "possible" : "impossible");
  return 0;
}
