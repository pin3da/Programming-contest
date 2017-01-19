#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  while (cin >> n && n) {
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < n; ++i)
      b[a[i] - 1] = i + 1;
    puts(a == b ? "ambiguous" : "not ambiguous");
  }
  return 0;
}
