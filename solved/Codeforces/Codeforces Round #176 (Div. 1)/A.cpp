// http://codeforces.com/contest/286/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(int n) {
  if ((n & 3) >= 2) {
    cout << -1 << endl;
    return;
  }
  vector<int> p(n);
  if (n & 1) {
    p[n >> 1] = n >> 1 | 1;
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] == 0) {
      p[i] = i + 2;
      p[i + 1] = n - i;
      p[n - i - 1] = n - i - 1;
      p[n - i - 2] = i + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << p[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
