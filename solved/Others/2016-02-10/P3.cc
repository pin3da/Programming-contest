#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  while (cin >> n >> k && (n + k) > 0) {
    int t = 0, p;
    map<int, int> f;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      f[p]++;
    }
    for (auto &i :f) {
      if (i.second >= k)
        t++;
    }
    cout << t << endl;
  }
  return 0;
}
