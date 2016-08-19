#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

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
int p[MLEN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin >> n;
  int len = 0;
  for (int i = 0; i < n; ++i) {
    char type; cin >> type;
    if (type == '-') {
      len--;
    } else {
      int x; cin >> x;
      if (len == 0) {
        version[len] = update(NULL, 0, MN, x, 1);
      } else {
        int lv = p[len - 1];
        version[len] = update(version[lv], 0, MN, x, len + 1);
        p[len] = get(version[lv], 0, MN, x);
      }
      len++;
    }
    cout << (len > 0 ? p[len - 1] : 0) << endl;
  }

  return 0;
}
