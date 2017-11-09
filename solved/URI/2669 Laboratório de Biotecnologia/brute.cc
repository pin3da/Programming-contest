#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  set<int> ans;
  int n = line.size();
  for (int i = 0; i < n; i++) {
    int acc = 0;
    for (int j = i; j < n; j++) {
      acc += line[j] - 'a' + 1;
      ans.insert(acc);
    }
  }
  cout << ans.size() << endl;
  return 0;
}
