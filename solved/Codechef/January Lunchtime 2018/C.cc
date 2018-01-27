// Chef and Function
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MAX = 500;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    map<long long, int> values;
    for (int i = 0; i < n; i++) {
      long long cur_xor = 0, cur_min = a[i];
      int j = i;
      for (; j < n && (j - i) <= MAX; j++) {
        cur_xor ^= a[j];
        cur_min = min<long long>(a[j], cur_min);
        values[cur_xor * cur_min]++;
      }

      values[cur_xor * cur_min] += (n - j);
    }

    for (auto it : values) {
      if (k <= it.second) {
        cout << it.first << endl;
        break;
      } else {
        k -= it.second;
      }
    }
  }

  return 0;
}
