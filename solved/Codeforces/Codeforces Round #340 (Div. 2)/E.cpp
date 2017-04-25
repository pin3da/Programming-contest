// http://codeforces.com/contest/617/problem/E

#include <bits/stdc++.h>

using namespace std;

struct query{
  int l, r, id;
  query() {}
  query(int a, int b, int c) : l(a), r(b), id(c) {}
  bool operator <(const query &o) const {
    return r < o. r;
  }
};

const int MV = (1 << 20) + 10;
struct ds{
  long long total = 0;
  int k;
  vector<int> p;
  vector<int> frec;
  ds(vector<int> &a, int _k) {
    k = _k;
    p.resize(a.size() + 1);
    for (int i = 0; i < a.size(); ++i)
      p[i + 1] = p[i] ^ a[i];
    frec.resize(MV);
  }

  void add(int i) {
    total += frec[p[i] ^ k];
    frec[p[i]]++;
  }

  void del(int i) {
    frec[p[i]]--;
    total -= frec[p[i] ^ k];
  }
};

void solve(int n) {
  int m, k;
  cin >> m >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int bs = ceil(sqrt(n)) + 1;
  vector<vector<query>> buckets(n / bs + 1);
  int l, r;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    l--;
    buckets[l / bs].push_back(query(l, r, i));
  }
  for (auto &b: buckets)
    sort(b.begin(), b.end());

  ds data(a, k);
  vector<long long> ans(m);
  for (int i = 0; i < buckets.size(); ++i) {
    l = r = i * bs;
    for (auto &q: buckets[i]) {
      while (r <= q.r) {
        data.add(r);
        r++;
      }
      while (l < q.l) {
        data.del(l);
        l++;
      }
      while (l > q.l) {
        l--;
        data.add(l);
      }
      // cout << q.l << " " << q.r << ":" << endl;
      // cout << "\t" << l << " " << r << " " << data.total << endl;
      ans[q.id] = data.total;
    }
    for (int j = l; j < r; j++) {
      data.del(j);
    }
  }

  for (auto &i : ans)
    cout <<  i << endl;
}

int main() {
  int n;
  while (cin >> n)
    solve(n);
  return 0;
}
