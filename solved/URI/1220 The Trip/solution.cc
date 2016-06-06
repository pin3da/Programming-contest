#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<long long> a(n);
    double t;
    for (auto &i : a) {
      cin >> t;
      i = round(t * 100);
    }
    long long tot = accumulate(a.begin(), a.end(), 0);
    long long extra = tot % n;
    tot -= extra;
    tot /= n;
    long long ans = 0;
    for (auto &i: a) {
      if (i > tot) {
        if (extra) {
          extra--;
          ans += i - tot - 1;
        } else {
          ans += i - tot;
        }
      }
    }
    cout << '$' << ans / 100 << '.' << setw(2) << setfill('0') << ans % 100 << endl;
  }
  return 0;
}
