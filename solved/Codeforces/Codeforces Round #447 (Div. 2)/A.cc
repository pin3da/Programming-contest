#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line; cin >> line;
  int ans = 0;
  int n = line.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (line[i] == 'Q' && line[j] == 'A' && line[k] == 'Q')
          ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
