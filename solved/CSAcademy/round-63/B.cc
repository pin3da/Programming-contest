#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int s, q, k;
  cin >> s >> q >> k;
  vector<int> p(q);
  for (auto &i : p)  cin >> i;
  sort(p.begin(), p.end());

  long double total = s;
  for (int i = 0; i < q; i++) {
    if (total * p[i] > k * 100.0) {
      total = (100.0 + p[i]) * total / 100.0;
    } else {
      total += k;
    }
  }

  cout << fixed << setprecision(12) << total << endl;

  return 0;
}
