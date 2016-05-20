#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool av(vector<int> &p, int id, int n) {
  if (id + n > p.size()) return false;
  for (int i = 0; i < n; ++i) {
    if (p[id + i] != 0) return false;
  }
  return true;
}

void mark(vector<int> &p, int id, int n, int mark) {
  for (int i = 0; i < n; ++i)
    p[id + i] = mark;
}

void debug(vector<int> &p) {
  for (int i = 0; i < p.size(); ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int c, n;
  while (cin >> c >> n) {
    vector<int> parking(c);
    long long ans = 0;
    for (int l = 0; l < n; ++l) {
      char op; int p, q;
      // debug(parking);
      cin >> op >> p;
      if (op == 'C') {
        cin >> q;
        int found = 0;
        for (int i = 0; i < c && !found; ++i) {
          if (av(parking, i, q)) {
            mark(parking, i, q, p);
            ans += 10;
            found = 1;
          }
        }
      } else {
        for (int i = 0; i < c; ++i)
          if (parking[i] == p)
            parking[i] = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
