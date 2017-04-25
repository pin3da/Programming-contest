// http://codeforces.com/contest/598/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

string simulate(string &line, int a, int b, int k) {
  int len = b - a + 1;
  string ans = line;
  for (int i = a; i <= b; ++i)
    ans[a + (i - a + k) % len] = line[i];
  return ans;
}

void solve(string line) {
  int m; cin >> m;
  int i, j, k;
  while (m--) {
    cin >> i >> j >> k;
    line = simulate(line, i - 1, j - 1, k);
  }
  cout << line << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) solve(line);
  return 0;
}
