#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  while (cin >> tc && tc) {
    string name, verd;
    int t;
    unordered_map<string, int> ans(tc);
    unordered_set<string> correct;
    for (int i = 0; i < tc; ++i) {
      cin >> name >> t >> verd;
      if (correct.count(name)) continue;
      if (verd == "correct") {
        correct.insert(name);
        ans[name] += t;
      } else {
        ans[name] += 20;
      }
    }
    cout << correct.size();
    int total = 0;
    for (auto &i : correct) total += ans[i];
    cout << ' ' << total << endl;
  }
  return 0;
}
