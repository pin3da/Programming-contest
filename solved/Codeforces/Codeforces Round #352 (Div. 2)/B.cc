#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; string line;
  while (cin >> t >> line) {
    if (line.size() > 26) {
      cout << -1 << endl;
    } else {
      set<char> s;
      for (auto &i : line) s.insert(i);
      cout << line.size() - s.size() << endl;
    }
  }
  return 0;
}
