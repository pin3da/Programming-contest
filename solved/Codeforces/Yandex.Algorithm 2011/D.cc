#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2 * 100000 + 100;
const int SN = 448;

struct query {
  int a, b, id;
  query() {}
  query(int x, int y, int i) : a(x), b(y), id(i) {}

  bool operator < (const query &o) const {
    return b < o.b;
  }
};


vector<query> s[SN];
long long ans[MN];
long long frec[1000000 + 100];

struct DS {
  long long ans = 0;
  void clear() {
    memset(frec, 0, sizeof frec);
    ans = 0;
  }
  void insert(long long x) {
    long long fx = frec[x]++;
    ans += (fx * 2 + 1) * x;
  }
  void erase(long long x) {
    long long fx = --frec[x];
    ans -= (fx * 2 + 1) * x;
  }
  long long query() {
    return ans;
  }
};

DS data;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, q;
  while (cin >> n >> q) {
    for (int i = 0; i < SN; ++i)
      s[i].clear();

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    for (int i = 0; i < q; ++i) {
      int b, e;
      cin >> b >> e;
      b--; e--;
      s[b / SN].emplace_back(b, e, i);
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
      cout << ans[i] << endl;
    }
  }

  return 0;
};

