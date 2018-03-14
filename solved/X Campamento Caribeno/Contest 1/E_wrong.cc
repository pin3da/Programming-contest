#include<bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


struct node {
  long long ans;
  node *left, *right;
  node() : ans(0), left(NULL), right(NULL) {}
};

typedef node* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node();
  if (cur) *ans = *cur;
  return ans;
}

const int MN = 200000 + 10;

void update(pnode cur) {
  assert(cur);
  long long ans = MN;
  if (cur->left)  ans = min(ans, cur->left->ans);
  if (cur->right) ans = min(ans, cur->right->ans);
  cur->ans = ans;
}

pnode modify(pnode cur, int b, int e, int l, int r, long long val) {
  pnode res = copy_node(cur);

  if (b > r || e < l) return res;
  if (l <= b && e <= r) {
    assert(b == e);
    res->ans = val;
    return res;
  }

  int mid = (b + e) >> 1;
  if (l <= mid)
    res->left = modify(res->left, b, mid, l, r, val);
  else
    res->right = modify(res->right, mid + 1, e, l, r, val);

  update(res);

  return res;
}

long long query(pnode cur, int b, int e, int l, int r) {
  if (!cur) return MN;

  if (b > r || e < l) return MN;
  if (l <= b && e <= r) return cur->ans;
  int mid = (b + e) >> 1;
  long long left = query(cur->left, b, mid, l, r);
  long long right = query(cur->right, mid + 1, e, l, r);
  return min(left, right);
}

struct event {
  int type, val, id;
  event() {}
  event(int a, int b, int c) : type(a), val(b), id(c) {}
};


int main() {
#ifndef LOCAL
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n, q;
  while (cin >> n >> q) {
    debug(n, q);
    vector<map<int, event> > events(n + 1);
    vector<map<int, pnode> > versions(n + 1);
    for (int i = 0; i < n; i++) {
      int tmp; cin >> tmp;
      events[i][0] = event(0, tmp, 0);
    }

    debug(q);

    vector<int> ans;
    for (int i = 0; i < q; i++) {
      int t, pos, x;
      cin >> t >> pos >> x;
      pos--;
      int tt = i + 1;
      if (t == 1) {
        ans.push_back(-1);
        tt = ans.size();
      }
      events[pos][i + 1] = event(t, x, tt);
    }
    debug(ans.size());

    versions[n][0] = NULL;
    for (int i = n - 1; i >= 0; i--) {
      for (auto it : events[i]) {
        int cur_time = it.first;
        int x = it.second.val;
        if (it.second.type == 0) {
          auto nxt = versions[i + 1].upper_bound(cur_time);
          nxt--;
          pnode cur = nxt->second;
          versions[i][cur_time] = modify(cur, 0, MN, x, x, i);
        } else {
          auto last = versions[i].end();
          last--;
          pnode cur = last->second;
          ans[it.second.id - 1] = query(cur, 0, MN, x, MN);
        }
      }
    }

    for (int i = 0; i < int(ans.size()); i++) {
      if (ans[i] >= MN)
        cout << -1 << endl;
      else
        cout << ans[i] + 1 << endl;
    }
  }
  return 0;
}

