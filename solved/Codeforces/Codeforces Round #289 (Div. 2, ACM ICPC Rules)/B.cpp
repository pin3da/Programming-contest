// http://codeforces.com/contest/509/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(int n, int k) {
  vector<int> pile(n);
  for (int i = 0; i < n; ++i)
    cin >> pile[i];


  vector<vector<int> > ans(n, vector<int>(k, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < pile[i]; ++j) {
      ans[i][j % k]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int s = 0; s < k; ++s) {
        if (fabs(ans[i][s] - ans[j][s]) > 1) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    int primero = true;
    for (int s = 0; s < k ; ++s) {
      for (int j = 0; j < ans[i][s]; ++j) {
        if (!primero) cout << " ";
        cout << s + 1;
        primero = false;
      }
    }
    cout << endl;
  }



}

int main() { ___

  int n, k;
  while (cin >> n >> k) {
    solve(n, k);
  }
  return 0;
}
