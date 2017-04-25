// http://codeforces.com/contest/632/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;

    string b;
    cin >> b;

    long long p[2][n], s[2][n];

    for (int i = 0; i < n; ++i) {
      int j = b[i] - 'A';
      p[j][i] = a[i];
      p[j ^ 1][i] = 0;
      if (i) {
        p[0][i] += p[0][i - 1];
        p[1][i] += p[1][i - 1];
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      int j = b[i] - 'A';
      s[j][i] = a[i];
      s[j ^ 1][i] = 0;
      if (i < n - 1) {
        s[0][i] += s[0][i + 1];
        s[1][i] += s[1][i + 1];
      }
    }

    long long best = max(p[1][n - 1], s[1][0]);
    best = max(best, max(p[0][n - 1], s[0][0]));

    for (int i = 0; i < n - 1; ++i) {
      best = max(best, p[0][i] + s[1][i + 1]);
      best = max(best, p[1][i] + s[0][i + 1]);
    }

    cout << best << endl;
  }
  return 0;
}
