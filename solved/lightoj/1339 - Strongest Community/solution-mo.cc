// TLE
#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MN = 100000 + 100;
// const int SN = 708;
const int SN = 500;


struct seg_tree {
  int n;  // array size
  int t[2 * MN];

  void clear(int len) {
    memset(t, 0, sizeof t);
    n = len;
  }

  void increase(int p, int value) {  // set value at position p
    for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
  }

  int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};

struct query {
  int a, b, id;
  query() {}
  query(int x, int y, int i) : a(x), b(y), id(i) {}

  bool operator < (const query &o) const {
    return b < o.b;
  }
};


vector<query> s[SN];
int ans[MN];
seg_tree tree;

struct DS {
  int c;
  void clear(int d) {
    c = d;
    tree.clear(c + 10);
  }
  void insert(int x) {
    tree.increase(x, +1);
  }
  void erase(int x) {
    tree.increase(x, -1);
  }
  long long query() {
    return tree.query(0, c + 1);
  }
};

DS data;

void solve() {
  int n, c, q;
  scanf("%d%d%d", &n, &c, &q);
  for (int i = 0; i < SN; ++i)
    s[i].clear();

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < q; ++i) {
    int b, e;
    scanf("%d%d", &b, &e);
    b--; e--;
    s[b / SN].push_back(query(b, e, i));
  }


  for (int i = 0; i < SN; ++i) {
    if (s[i].size())
      sort(s[i].begin(), s[i].end());
  }

  for (int b = 0; b < SN; ++b) {
    if (s[b].size() == 0) continue;
    int i = s[b][0].a;
    int j = s[b][0].a - 1;

    data.clear(c);
    for (int k = 0; k < (int)s[b].size(); ++k) {
      int L = s[b][k].a;
      int R = s[b][k].b;

      while (j < R) {
        j++;
        data.insert(a[j]);
      }

      while (j > R) {
        data.erase(a[j]);
        j--;
      }

      while (i < L) {
        data.erase(a[i]);
        i++;
      }

      while (i > L) {
        i--;
        data.insert(a[i]);
      }
      ans[s[b][k].id] = data.query();
    }
  }

  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
}


int main() {
  int tc;
  scanf("%d", &tc);

  for (int i = 1; i <= tc; i++) {
    printf("Case %d:\n", i);
    solve();
  }
  return 0;
}

