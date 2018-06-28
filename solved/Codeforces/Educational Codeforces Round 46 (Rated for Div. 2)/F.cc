// MLE test 69 ):
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MN = 5 * 100000 + 1;
const int SN = 708;

struct query {
  int a, b, id;
  query() {}
  query(int x, int y, int i) : a(x), b(y), id(i) {}

  bool operator<(const query &o) const { return b < o.b; }
};

vector<query> s[SN];
int ans[MN];

struct DS {
  vector<int> frec, ans;

  DS () : frec(MN) {}

  void clear() {
    fill(frec.begin(), frec.end(), 0);
    ans.clear();
  }

  void insert(int x) {
    frec[x]++;
    int f = frec[x];
    if (f == 1) ans.push_back(x);
  }

  void erase(int x) {
    frec[x]--;
    int f = frec[x];
    if (f == 1) ans.push_back(x);
  }

  long long query() {
    while (ans.size() && frec[ans.back()] != 1) ans.pop_back();
    return ans.size() ? ans.back() : 0;
  }
};

DS active;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int b, e;
    cin >> b >> e;
    b--;
    e--;
    s[b / SN].emplace_back(b, e, i);
  }

  for (int i = 0; i < SN; ++i) {
    if (s[i].size()) sort(s[i].begin(), s[i].end());
  }

  for (int b = 0; b < SN; ++b) {
    if (s[b].size() == 0) continue;
    int i = s[b][0].a;
    int j = s[b][0].a - 1;

    active.clear();
    for (int k = 0; k < (int)s[b].size(); ++k) {
      int L = s[b][k].a;
      int R = s[b][k].b;

      while (j < R) active.insert(a[++j]);
      while (j > R) active.erase(a[j--]);
      while (i < L) active.erase(a[i++]);
      while (i > L) active.insert(a[--i]);

      ans[s[b][k].id] = active.query();
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
};
