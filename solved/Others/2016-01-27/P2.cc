#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, l, c;
  while (cin >> n >> l >> c) {
    int ans = 0, line = 0, lines = 1;
    string word;
    while (n--) {
      cin >> word;
      if (line + (line != 0) + word.size() <= c) {
        line += word.size() + (line != 0);
      } else {
        lines++;
        line = word.size();
        if (lines > l) {
          lines = 1;
          ans++;
        }
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
