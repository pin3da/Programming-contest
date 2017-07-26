#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());

  int missing = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    missing++;
    if ((i + 1 >= n) || ((a[i] & 1 ) && (a[i] + 1) == a[i + 1])) {
      i++;
    }
  }
  cout << missing << endl;
  return 0;
}
