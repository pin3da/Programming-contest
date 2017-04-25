// http://codeforces.com/contest/234/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> neg(n), pos(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) neg[i]++;
    if (i) neg[i] += neg[i - 1];
    if (a[n - i - 1] <= 0) pos[n - i - 1]++;
    if (i) pos[n - i - 1] += pos[n - i];
  }

  int best = n;
  for (int i = 0; i  + 1 < n; ++i) {
    best = min(best, neg[i] + pos[i + 1]);
  }
  cout << best << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
