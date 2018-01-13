#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  int best = 10000;
  for (auto &i : a) {
    cin >> i;
    if ((k % i) == 0) {
      best = min(best, k / i);
    }
  }

  cout << best << endl;

  return 0;
}
