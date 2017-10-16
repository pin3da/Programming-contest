#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> all(n);
  for (auto &i : all) cin >> i;
  sort(all.begin(), all.end());
  int last = all.back();
  cout << max(0, last - 25) << endl;
  return 0;
}
