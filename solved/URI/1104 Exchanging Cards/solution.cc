#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    set<int> a, b;
    int t;
    while (n--) {
      cin >> t;
      a.insert(t);
    }
    while (m--) {
      cin >> t;
      b.insert(t);
    }

    set<int> aa, bb;
    for (auto &i : a) if (!b.count(i)) aa.insert(i);
    for (auto &i : b) if (!a.count(i)) bb.insert(i);
    cout << min(aa.size(), bb.size()) << endl;
  }
  return 0;
}
