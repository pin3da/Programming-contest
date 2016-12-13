#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  vector<int> frec(111);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    frec[t]++;
  }

  int best = 0;
  for (int i = 0; i + 1 < (int)frec.size(); ++i) {
    best = max(best, frec[i] + frec[i + 1]);
  }
  cout << best << endl;
  return 0;
}
