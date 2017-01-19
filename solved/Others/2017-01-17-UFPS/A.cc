#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string line;
  while (cin >> line && line != "0") {
    set<int> ans;
    while (ans.count(stoll(line)) == 0) {
      long long a = stoll(line);
      ans.insert(a);
      a = a * a;
      line = to_string(a);
      while (line.size() < 8) line = '0' + line;
      line = line.substr(2, 4);
    }
    cout << ans.size() << endl;
  }
  return 0;
}
