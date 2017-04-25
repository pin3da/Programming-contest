// http://codeforces.com/contest/609/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve(int n, int m) {
  vector<int> type(m);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    type[t - 1]++;
  }

  long long ans = 0;
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < m; ++j)
      ans += type[i] * type[j];
  cout << ans << endl;
}

int main() {
  int n, m;
  while(cin >> n >> m)
    solve(n, m);
  return 0;
}
