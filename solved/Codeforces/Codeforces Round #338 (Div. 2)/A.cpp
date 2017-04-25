// http://codeforces.com/contest/615/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> seen(m);
    int t, x;
    while (n--) {
      cin >> t;
      while (t--) {
        cin >> x; x--;
        seen[x] = true;
      }
    }

    if (accumulate(seen.begin(), seen.end(), 0) == m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
