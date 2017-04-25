// http://codeforces.com/contest/522/problem/B

using namespace std;
#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(int n) {
  vector<int> a(n), c(n);
  map<long long, long long> b;
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
    total += a[i];
    b[c[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    long long x = total - a[i];
    auto it = b.end();
    it--;
    if (it-> second == 1 && c[i] == it-> first)
      it--;
    if (i) cout << " ";
    cout << x * it-> first;
  }
  cout << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n)
    solve(n);
  return 0;
}
