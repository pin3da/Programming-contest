#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    string a, b;
    unordered_map<string, string> sg;
    while (n--) {
      cin >> a >> b;
      sg[a] = b;
    }
    int m;
    cin >> m;
    int ans = 0;
    while (m--) {
      cin >> a >> b;
      string c = sg[a];
      if (c.size() != b.size()) {
        ans++;
        continue;
      }

      int bad = 0;
      for (int i = 0; i < c.size(); ++i)
        if (c[i] != b[i])
          bad++;

      ans += bad > 1;
    }
    cout << ans << endl;
  }
  return 0;
}

