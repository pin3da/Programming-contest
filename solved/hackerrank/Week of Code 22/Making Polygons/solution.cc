#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    if (n == 1) {
      cout << 2 << endl;
      continue;
    }

    if (n == 2) {
      cout << 1 + (a[0] == a[1]) << endl;
      continue;
    }

    sort(a.rbegin(), a.rend());
    if (a[0] >= accumulate(a.begin() + 1, a.end(), 0))
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
