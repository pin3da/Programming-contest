#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  sort(a.rbegin(), a.rend());

  int ok = false;
  for (int i = 0; i + 2 < a.size(); ++i) {
    if (a[i] < a[i + 1] + a[i + 2])
      ok = true;
  }

  puts(ok ? "YES" : "NO");
  return 0;
}
