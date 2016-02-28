using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

bool check(vector<long long> &a, int t, long long val) {
  int n = a.size() / 2;
  for (int i = 0; i < n; ++i) {
    long long ant = 0;
    if (i) ant = a[i - 1];
    int q = 0, limit = i + n;
    long long tar = val + ant;
    while (q < t) {
      vector<long long>::iterator carlos = lower_bound(a.begin() + i, a.end(), tar);
      if (*carlos != tar) break;
      if ((carlos - a.begin()) < limit) {
        q++;
        tar += val;
      } else {
        break;
      }
    }
    if (q == t)
      return true;
  }

  return false;
}

void solve(int n) {
  vector<long long> a(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  for (int i = 1; i < a.size(); ++i)
    a[i] += a[i - 1];

  long long tot = a[n - 1];
  for (int i = n; i >= 3; --i) {
    if (tot % i != 0) continue;
    if (check(a, i, tot / i)) {
      cout << i << endl;
      return;
    }
  }

  cout << -1 << endl;
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }

  return 0;
}
