#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, k;
  while (cin >> n >> k) {
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    long long total = accumulate(a.begin(), a.end(), 0),
         extra = total % n,
         real  = (total - extra) / n,
         diff  = 0;

    for (int i = 0; i < n; ++i) {
      diff += abs(a[i] - real);
    }

    long long happy = (diff >> 1) + extra;

    if (k >= happy) {
      cout << (extra != 0) << endl;
    } else {
      map<int, int> s;
      for (int i = 0; i < n; ++i) {
        s[a[i]]++;
      }

      while (k--) {
        int a = (s.begin())-> first;
        auto e = s.end();
        e--;
        int b = e-> first;
        if (a < b) {
          s[a]--;
          s[b]--;
          if (s[a] == 0) s.erase(a);
          if (s[b] == 0) s.erase(b);
          s[++a]++;
          s[--b]++;
        }
      }
      int a = (s.begin())-> first;
      auto e = s.end();
      e--;
      int b = e-> first;
      cout << b - a << endl;

    }
  }
  return 0;
}
