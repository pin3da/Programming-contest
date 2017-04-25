// http://codeforces.com/contest/560/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  vector<int> a(n);

  for (auto &i : a) cin >> i;

  sort(a.begin(), a.end());
  if (a[0] == 1) {
    cout << -1 << endl;
  } else {
    cout << 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n) solve(n);
  return 0;
}
