#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> r(n);

    for (int i = 1; ; ++i) {
      vector<int> alive(n);
      for (int j = 0; j < n; ++j)
        alive[j] = j + 1;
      int cur = 0;
      while (alive.size()) {
        if (alive[cur] == 13) {
          break;
        }
        alive.erase(alive.begin() + cur);
        cur += (i - 1);
        cur %= alive.size();
      }
      if (alive.size() == 1) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
