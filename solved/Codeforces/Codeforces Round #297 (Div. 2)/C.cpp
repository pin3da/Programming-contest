// http://codeforces.com/contest/525/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i];
    }
    sort(l.rbegin(), l.rend());

    int op = 0;
    int i = 0, j = 1;
    long long ans = 0, a, b;
    while (i < n && j < n) {
      if (fabs(l[i] - l[j]) <= 1) {
        if (op == 0) {
          a = l[j];
          op = 1;
        } else {
          ans += a * (long long) l[j];
          op = 0;
        }
        i += 2;
        j += 2;
      } else {
        i++;j++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

