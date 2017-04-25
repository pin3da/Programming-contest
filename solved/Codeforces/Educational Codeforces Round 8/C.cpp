// http://codeforces.com/contest/628/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dist[255][255];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  string line;

  for (char a = 'a'; a <= 'z'; ++a) {
    for (char b = a + 1; b <='z'; ++b) {
      dist[b][a] = dist[a][b] = b - a;
    }
  }
  while (cin >> n >> k >> line) {
    string ans = line;
    for (int i = 0; i < line.size() && k; ++i) {
      int max_dist = dist[line[i]]['z'];
      char tt = 'z';
      if (dist[line[i]]['a'] > max_dist) {
        max_dist = dist[line[i]]['a'];
        tt = 'a';
      }
      if (max_dist <= k) {
        ans[i] = tt;
        k -= max_dist;
      } else {
        if (tt == 'z')
          ans[i] = line[i] + k;
        else
          ans[i] = line[i] - k;
        k = 0;
      }
    }
    if (k == 0)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }

  return 0;
}
