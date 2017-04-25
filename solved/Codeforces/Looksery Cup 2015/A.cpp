// http://codeforces.com/contest/549/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x)  << endl
#define endl '\n'


char g[55][55];
int n, m;

int count(int i, int j) {
  vector<int> frec(30, 0);
  frec[g[i][j] - 'a']++;
  if (i + 1 < n)
    frec[g[i + 1][j] - 'a']++;
  if (j + 1 < m)
    frec[g[i][j + 1] - 'a']++;
  if (i + 1 < n && j + 1 < m)
    frec[g[i + 1][j + 1] - 'a']++;

  return frec['f' - 'a'] &&  frec['a' - 'a'] &&  frec['c' - 'a']  &&  frec['e' - 'a'] ;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i <  n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i <  n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += count(i, j);
    }
  }
  cout << ans << endl;


  return 0;
}
