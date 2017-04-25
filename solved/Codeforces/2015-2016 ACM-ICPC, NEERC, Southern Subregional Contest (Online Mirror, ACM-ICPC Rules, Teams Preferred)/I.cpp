// http://codeforces.com/contest/589/problem/I

using namespace std;
#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> col(m);
    int t;
    for (int i = 0; i <  n; ++i) {
      cin >> t;
      col[t - 1]++;
    }

    int tar = n / m;
    int ans = 0;
    for (int i = 0; i < m; ++i)
      ans += abs(tar - col[i]);

    cout << (ans >> 1) << endl;
  }
  return 0;
}
