#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

using namespace std;

const int MN = 79;

int fun(int x, int y) {
  int ans = 0;
  set<int> seen;
  while (x > 0) {
    seen.insert(x % 10);
    x /= 10;
    ans++;
  }
  while (ans < 5) {
    seen.insert(0);
    ans++;
  }

  while (y > 0) {
    seen.insert(y % 10);
    y /= 10;
    ans++;
  }
  while (ans < 10) {
    seen.insert(0);
    ans++;
  }
  return ans == seen.size();
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<vector<int>> a(MN + 1);

  for (int i = 2; i <= 79; ++i) {
    for (int j = 1234; i * j < 100000; ++j) {
      int t = j * i;
      if (fun(t, j)) {
        a[i].push_back(j);
      }
    }
  }
  int q;

  int first = true;
  while (cin >> q && q) {
    if (!first) puts("");
    first = 0;
    if (a[q].size() == 0) {
      // cout << "There are no solutions for " << q << "." << endl;
      printf("There are no solutions for %d.\n", q);
      continue;
    }
    for (int i = 0; i < a[q].size(); ++i) {
      // cout << a[q][i] * q << " / " << a[q][i] << " = " << q << endl;
      printf("%05d / %05d = %d\n", a[q][i] * q, a[q][i], q);
    }
  }
  return 0;
}
