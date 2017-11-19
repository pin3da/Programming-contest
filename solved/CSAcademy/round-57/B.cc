#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, k;
  cin >> n >> k;
  string line;
  cin >> line;
  if (line.find('1') == string::npos) {
    cout << n * k << endl;
  } else {
    string t;
    for (int i = 0; i < min<int>(k, 2); i++) {
      t += line;
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < (int)t.size(); i++) {
      if (t[i] == '1') {
        ans = max(ans, cur);
        cur = 0;
      } else {
        cur++;
      }
    }
    ans = max(ans, cur);
    cout << ans << endl;
  }

  return 0;
}
