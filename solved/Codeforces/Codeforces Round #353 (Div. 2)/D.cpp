// http://codeforces.com/contest/675/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

#define null NULL

struct t_node {
  int val;
  t_node *l, *r, *p;
  t_node(int k) : l(null), r(null), p(null), val(k) {}
};

typedef t_node* pnode;

unordered_map<int, pnode> ans;

const int inf = 1000 * 1000 * 1000 + 10;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    pnode root = null;
    ans.clear();
    vector<int> input(n);
    set<int> seen;
    int t;
    cin >> t;
    seen.insert(t);
    seen.insert(-1);
    seen.insert(inf);
    root = new t_node(t);
    ans[t] = root;
    for (int i = 1; i < n; ++i) {
      cin >> t;
      input[i] = t;
      auto hi = seen.upper_bound(t);
      auto lo = seen.lower_bound(t);lo--;
      int a = *lo, b = *hi;
      pnode cur = new t_node(t);
      ans[t] = cur;
      // cout << t << " " << a << " " << b << endl;
      if (a != -1 && b != inf) {
        if (ans[a]-> r == null) {
          ans[a]-> r = cur;
          cur-> p = ans[a];
        } else if (ans[b]-> l == null) {
          ans[b]-> l = cur;
          cur-> p = ans[b];
        } else {
        }
      } else if (a != -1) {
        if (ans[a]-> r == null) {
          ans[a]-> r = cur;
          cur-> p = ans[a];
        }
      } else {
        if (ans[b]-> l == null) {
          ans[b]-> l = cur;
          cur-> p = ans[b];
        }
      }
      seen.insert(t);
    }
    for (int i = 1; i < n; ++i) {
      if (i > 1) cout << " ";
      cout << ans[input[i]]-> p -> val;
    }
    cout << endl;
  }
  return 0;
}
