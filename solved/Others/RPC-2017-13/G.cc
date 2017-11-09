#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000123;
struct counter {
  int frec[MN];
  int total;
  int unique;

  void clear() {
    memset(frec, 0, sizeof frec);
    total = 0;
    unique = 0;
  }

  void add(vector<int> &data) {
    for (int i = 0; i < data.size(); i++) {
      if (frec[data[i]] == 0) unique++;
      frec[data[i]]++;
      total++;
    }
  }

  void rem(vector<int> &data) {
    for (int i = 0; i < data.size(); i++) {
      frec[data[i]]--;
      if (frec[data[i]] == 0) unique--;
      total--;
    }
  }
};

counter frec;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  while (cin >> n >> k) {
    vector<vector<int>> data(n);
    for (int i = 0; i < n; i++) {
      int l; cin >> l;
      for (int j = 0; j < l; j++) {
        int tmp; cin >> tmp;
        data[i].push_back(tmp);
      }
    }

    frec.clear();
    int i = 0, j = 0;
    int best = 1e8;
    while (i < 2 * n) {
      while (j < 2 * n) {
        if (frec.unique < k) {
          frec.add(data[j % n]);
          j++;
        } else {
          break;
        }
      }
      if (frec.unique == k) {
        best = min(best, frec.total);
      }
      frec.rem(data[i % n]);
      i++;
    }

    if (best == 1e8) {
      cout << -1 << endl;
    } else {
      cout << best << endl;
    }
  }
  return 0;
}
