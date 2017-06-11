#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct state {
  long long  a, b, c;
  state(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
  bool operator <(const state &s) const {
    if (a == s.a) {
      if (b == s.b) {
        return c < s.c;
      }
      return b < s.b;
    }
    return a < s.a;
  }
};

long long a, b, c;

void calc(vector<state> &s, vector<state> &sum) {
  int sz = s.size();
  for (int i = 0; i < (1 << sz); i++) {
    state tmp(0,0,0);
    bool ok = true;
    for (int j = 0; j < sz; j++) {
      if ((i & (1 << j)) != 0) {
        tmp.a += s[j].a;
        tmp.b += s[j].b;
        tmp.c += s[j].c;
        if (tmp.a > a || tmp.b > b || tmp.c > c) {ok = false; break;}
      }
    }
    if (ok) sum.push_back(tmp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int t; cin >> t;
  while(t--) {
    long long r, x, y, z;
    cin >> a >> b >> c >> r;
    int lis = r >> 1;
    vector<state> m1, m2, s1, s2;
    for (int i = 0; i < r; i++) {
      cin >> s >> x >> y >> z;
      if (i < lis) m1.push_back(state(x, y, z));
      else         m2.push_back(state(x, y, z));
    }
    bool ok = false;
    calc(m1, s1);
    calc(m2, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < (int)s1.size(); i++) {
      state ss(a - s1[i].a, b - s1[i].b, c - s1[i].c);
      if (binary_search(s2.begin(), s2.end(), ss)) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}
