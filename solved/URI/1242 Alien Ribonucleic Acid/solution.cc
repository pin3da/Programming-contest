#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string p[] = {"BS", "SB", "CF", "FC"};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string line;
  while (cin >> line) {
    int ans = 0;
    while (line.size() > 1) {
      int seen = 0;
      for (auto &t : p) {
        int id;
        if ((id = line.find(t)) == string::npos) continue;
        string tp = line.substr(0, id) + line.substr(id + 2);
        line = tp;
        ans++;
        seen = true;
        break;
      }
      if (!seen) break;
    }
    cout << ans << endl;
  }
  return 0;
}
