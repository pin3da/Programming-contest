#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


const int MLEN = 2 * 100000 + 100;
const int MN = MLEN * 20; // Mlen * log (Mlen)

struct node {
  node *l, *r;
  int val;

  node (int x) : l(NULL), r(NULL), val(x) {}
  node () : l(NULL), r(NULL), val(-1) {}
};

typedef node* pnode;

pnode update(pnode cur, int l, int r, int at, int what) {
  pnode ans = new node();

  if (cur != NULL) {
    *ans = *cur;
  }
  if (l == r) {
    ans-> val = what;
    return ans;
  }
  int m = (l + r) >> 1;
  if (at <= m) ans-> l = update(ans-> l, l, m, at, what);
  else ans-> r = update(ans-> r, m + 1, r, at, what);
  return ans;
}

int get(pnode cur, int l, int r, int at) {
  if (cur == NULL) return 0;
  if (l == r) return cur-> val;
  int m = (l + r) >> 1;
  if (at <= m) return get(cur-> l, l, m, at);
  else         return get(cur-> r, m + 1, r, at);
}

pnode version[MLEN];
int ini[MLEN], fin[MN];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int cur = 0;

  int q; cin >> q;

  version[cur] = update(NULL, 0, MN, 0, 0);
  ini[cur] = 0;
  fin[cur] = -1;

  while (q--) {
    char t; cin >> t;
    cur++;
    if (t == 'E') {
      int ver, val;
      cin >> ver >> val;
      ini[cur] = ini[ver];
      fin[cur] = fin[ver] + 1;
      version[cur] = update(version[ver], 0, MN, fin[cur], val);
    } else {
      int ver; cin >> ver;
      cout << get(version[ver], 0, MN, ini[ver]) << endl;
      // needed to create new version.
      version[cur] = update(version[ver], 0, MN, ini[ver], -1);
      ini[cur] = ini[ver] + 1;
      fin[cur] = fin[ver];
    }
  }

  return 0;
}
