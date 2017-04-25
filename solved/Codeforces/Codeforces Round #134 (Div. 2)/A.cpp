// http://codeforces.com/contest/218/problem/A

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  int k; cin >> k;
  vector<int> a(n << 1 | 1);
  for (auto &i : a)
    cin >> i;

  for (int i = 0; i + 1 < a.size() && k; ++i) {
    if (i & 1) {
      if (a[i - 1] < a[i] - 1 && a[i] - 1 > a[i + 1]) {
        a[i]--;
        k--;
      }
    }
  }

  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n) solve(n);
  return 0;
}
