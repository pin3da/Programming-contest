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

struct Query {
  int a, b, id;
  Query() {}
  Query(int x, int y, int i) : a(x), b(y), id(i) {}

  bool operator<(const Query &o) const {
    if (a / SN != o.a / SN) return a < o.a;
    return a / SN & 1 ? b < o.b : b > o.b;
  }
};


struct DS {
  vector<int> frec, ans;
  vector<bool> seen;

  DS () : frec(MN), seen(MN) {}

  void Insert(int x) {
    frec[x]++;
    if (frec[x] == 1 && !seen[x]) {
      ans.push_back(x);
      seen[x] = true;
    }
  }

  void Erase(int x) {
    frec[x]--;
    if (frec[x] == 1 && !seen[x]) {
      ans.push_back(x);
      seen[x] = true;
    }
  }

  long long Query() {
    while (ans.size() && frec[ans.back()] != 1) {
      seen[ans.back()] = false;
      ans.pop_back();
    }
    return ans.size() ? ans.back() : 0;
  }
};

Query s[MN];
int ans[MN];
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
    s[i] = Query(b, e, i);
  }

  sort(s, s + q);

  int i = 0;
  int j = -1;
  for (int k = 0; k < (int)q; ++k) {
    int L = s[k].a;
    int R = s[k].b;

    while (j < R) active.Insert(a[++j]);
    while (j > R) active.Erase(a[j--]);
    while (i < L) active.Erase(a[i++]);
    while (i > L) active.Insert(a[--i]);

    ans[s[k].id] = active.Query();
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
};
