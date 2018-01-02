#include<bits/stdc++.h>

using namespace std;

const int MN = 5 * 100000 + 100;
const int SN = 708;

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

struct DS {
  int data[MN];
  int len;

  void clear() {
    memset(data, 0, sizeof data);
    len = 0;
  }
  void insert(int x) {
    if (data[x] == 0) len++;
    data[x]++;
  }
  void erase(int x) {
    data[x]--;
    if (data[x] == 0) len--;
  }
  long long query() {
    return len;
  }
};

DS data;

void solve() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 0; i < SN; ++i)
    s[i].clear();

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < q; ++i) {
    int b, e;
    cin >> b >> e;
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

    data.clear();
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

