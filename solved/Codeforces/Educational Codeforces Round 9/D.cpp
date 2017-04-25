// http://codeforces.com/contest/632/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;

  while (cin >> n >> m) {
    vector<int> a(n);
    vector<long long> frec(m + 10);
    for (auto &i : a) {
      cin >> i;
      if (i <= m)
        frec[i]++;
    }

    long long best = 0;
    long long id = 1;

    for (long long i = m; i >= 0; --i)
      if (frec[i])
        for (long long j = i + i; j <= m; j += i)
          frec[j] += frec[i];

    for (int i = 0; i <= m; ++i)
      if (frec[i] > best) {
        best = frec[i];
        id = i;
      }

    cout << id << ' ' << best << endl;
    for (int i = 0; i < n; ++i) {
      if ((id % a[i]) == 0)
        cout << i + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
