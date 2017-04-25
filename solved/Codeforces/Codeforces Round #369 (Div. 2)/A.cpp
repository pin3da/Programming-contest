// http://codeforces.com/contest/711/problem/A

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<string> line(n);
    int seen = 0;
    for (int i = 0; i < n; ++i) {
      cin >> line[i];
      if (!seen) {
        if ((line[i][0] == line[i][1]) && line[i][0] == 'O') {
          line[i][0] = line[i][1] = '+';
          seen = true;
        }
        if (!seen)
        if ((line[i][3] == line[i][4]) && line[i][3] == 'O') {
          line[i][4] = line[i][3] = '+';
          seen = true;
        }
      }
    }
    if (!seen) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) {
        cout << line[i] << endl;
      }
    }
  }

  return 0;
}
