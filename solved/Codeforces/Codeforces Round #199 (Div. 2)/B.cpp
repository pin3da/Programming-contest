// http://codeforces.com/contest/342/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve(int n) {
  int m, s, f; cin >> m >> s >> f;
  int delta = 1;
  if (s > f) delta *= -1;
  int t;
  vector<int> a(n + 10, -1), b(n + 10, -1);
  while (m--) {
    cin >> t;
    if (t < a.size())
      cin >> a[t] >> b[t];
    else
      cin >> t >> t;
  }
  int i = 1;
  while (s != f) {
    if (i < a.size() && a[i] != -1 && (a[i] <= s && s <= b[i]
            || (a[i] <= s + delta && s + delta <= b[i]))) cout << "X";
    else {
      s += delta;
      if (delta > 0) cout << "R";
      else           cout << "L";
    }
    i++;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
