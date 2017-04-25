// http://codeforces.com/contest/513/problem/B1

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() { ___

  int n, m; cin >> n >> m;
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    p.push_back(i + 1);
  }

  int best  = 0;
  do {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cur = p[i];
      for (int j = i; j < n; ++j) {
        for (int k = i; k <= j; ++k) {
          if (p[k] < cur)
            cur = p[k];
        }
        ans += cur;
      }
    }

    if (best < ans)
      best = ans;
    /*
     * if (ans == 20) {
     *cout << ans << " : ";
     *for (int i = 0; i < n; ++i) {
     *  cout  << p[i] << " ";
     *}
     *cout << endl;
     *}
     */
  } while(next_permutation(p.begin(), p.end()));

  sort(p.begin(), p.end());
  do {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cur = p[i];
      for (int j = i; j < n; ++j) {
        for (int k = i; k <= j; ++k) {
          if (p[k] < cur)
            cur = p[k];
        }
        ans += cur;
      }
    }

    if (ans == best) {
      m--;
      if (m == 0) {
        for (int i = 0; i < n; ++i) {
          cout  << p[i] << " ";
        }
        cout << endl;
        return 0;
      }
    }
  } while(next_permutation(p.begin(), p.end()));



  return 0;
}
