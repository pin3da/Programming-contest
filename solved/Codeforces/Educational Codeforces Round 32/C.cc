#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int get_sum(vector<vector<int>> &f, int row, int from, int to) {
  if (to < from) return 0;
  int ans = f[to][row];
  if (from)
    return ans - f[from - 1][row];
  return ans;
}

int test(vector<vector<int>> &f, int len) {
  for (int i = 0; i < 26; i++) {
    int ok = true;
    for (int j = 0; ok && j + len - 1 < (int)f.size(); j++) {
      ok &= get_sum(f, i, j, j + len - 1) > 0;
    }
    if (ok) {
      return true;
    }
  }
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  vector<vector<int>> frec(line.size(), vector<int> (26));

  for (int i = 0; i < (int)line.size(); i++) {
    frec[i][line[i] - 'a'] = 1;
    if (i) {
      for (int j = 0; j < 26; j++) {
        frec[i][j] += frec[i - 1][j];
      }
    }
  }

  int lo = 0, hi = line.size();
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (test(frec, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
