#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void gen_divs(int n, set<int> &ans) {
  for (int i = 1; i * i <= n; ++i) {
    if ((n % i) == 0) {
      ans.insert(i);
      if ((n / i) != i)
        ans.insert(n / i);
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    long long ans = 0;
    for (int A = 1; A < n; ++A) {
      set<int> s;
      for (int i = 1; A * i < n; ++i) {
        int B = n - A * i;
        gen_divs(B, s);
      }
      for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        if ((*it) > A) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
