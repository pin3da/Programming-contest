#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    string line;
    set<string> p;
    while (n--) {
      cin >> line;
      p.insert(line);
    }
    cout << p.size() << endl;
  }
  return 0;
}
