#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int f(vector<int> c, int i, int j) {
  return c[0] * i + c[1] * j;
}


int f(vector<int> c, int i, int j, int k) {
  return c[0] * i + c[1] * j + c[2] * k;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> c(n);
    for (auto &i : c) cin >> i;
    if (n == 1) {
      cout << "Lucky Denis!" << endl;
      continue;
    }
    if (n == 2) {
      unordered_set<int> seen;
      int ok = true;
      for (int i = 0; i < m && ok; ++i) {
        for (int j = 0; j < m && ok; ++j) {
          if (seen.count(f(c, i, j)))
            ok = false;
          else
            seen.insert(f(c, i, j));
        }
      }
      if (ok)
        cout << "Lucky Denis!" << endl;
      else
        cout << "Try again later, Denis..." << endl;
      continue;
    }
    unordered_set<int> seen;
    int ok = true;
    for (int i = 0; i < m && ok; ++i) {
      for (int j = 0; j < m && ok; ++j) {
        for (int k = 0; k < m && ok; ++k) {
          if (seen.count(f(c, i, j, k)))
            ok = false;
          else
            seen.insert(f(c, i, j, k));
        }
      }
    }
    if (ok)
      cout << "Lucky Denis!" << endl;
    else
      cout << "Try again later, Denis..." << endl;
  }

  return 0;
}
