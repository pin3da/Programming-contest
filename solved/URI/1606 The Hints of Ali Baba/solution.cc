#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    unordered_set<int> seen(k);
    int first = true;
    for (auto &i : a) {
      cin >> i;
      if (seen.count(i) == 0) {
        if (!first) cout << ' ';
        cout << i;
        first = 0;
        seen.insert(i);
      }
    }
    cout << endl;
  }
  return 0;
}
