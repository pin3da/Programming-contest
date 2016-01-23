#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN  = 40;
typedef unsigned int uint;

struct matrix {
  int r, c;
  uint m[MN][MN];

  matrix() {}
  matrix (int _r, int _c) : r (_r), c (_c) {
    memset(m, 0, sizeof m);
  }

  void print() {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        cout << m[i][j] << " ";
      cout << endl;
    }
  }

  uint x[MN][MN];
  matrix & operator *= (const matrix &o) {
    memset(x, 0, sizeof x);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (m[i][k] != 0)
          for (int j = 0; j < c; ++j) {
            x[i][j] = x[i][j] +  m[i][k] * o.m[k][j];
          }
    memcpy(m, x, sizeof(m));
    return *this;
  }
};

void matrix_pow(matrix b, long long e, matrix &res) {
  memset(res.m, 0, sizeof res.m);
  for (int i = 0; i < b.r; ++i)
    res.m[i][i] = 1;

  if (e == 0) return;
  while (true) {
    if (e & 1) res *= b;
    if ((e >>= 1) == 0) break;
    b *= b;
  }
}

matrix a, b;


void solve(vector<vector<uint> > &t) {
  int n;
  scanf("%d", &n);
  a.r = a.c = t.size();
  b.r = b.c = t.size();
  for (int i = 0; i < t.size(); ++i)
    for (int j = 0; j < t.size(); ++j)
      a.m[i][j] = t[i][j];

  matrix_pow(a, n, b);
  uint ans = 0;
  for (int i = 1; i < t.size(); ++i) {
    ans += b.m[0][i];
  }
  printf("%u\n", ans);
}

void gen_transitions(vector<vector<uint> > &t, vector<pair<int, int> > &s) {
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s.size(); ++j) {
      if (abs(s[i].first - s[j].first) > 1 &&
          abs(s[i].first - s[j].second) > 1 &&
          abs(s[i].second - s[j].first) > 1 &&
          abs(s[i].second - s[j].second) > 1) {

        t[i][j] = 1;
      }
    }
    t[i][0] = 0;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  vector<pair<int, int> > state;
  state.push_back(make_pair(-10, -12));
  for (int i = 0; i < 10; i++)
    for (int j = i + 2; j < 10; ++j)
      state.push_back(make_pair(i, j));

  vector<vector<uint> > t(state.size(), vector<uint> (state.size()));
  gen_transitions(t, state);

  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve(t);
  }
  return 0;
}
