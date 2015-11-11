#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    int open = 0, ans = 0;
    char t;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> t;
        if (open || (t != '.')) {
          ans++;
          if (t == '.')
            ans++;
        }
        if (t != '.')
          open ^= 1;
      }
    }
    cout << (ans >> 1) << endl;
  }
  return 0;
}
