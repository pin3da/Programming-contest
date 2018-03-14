#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

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

void update(pnode cur) {
  assert(cur);
  long long ans = 0;
  if (cur->left)  ans += cur->left->ans;
  if (cur->right) ans += cur->right->ans;
  cur->ans = ans;
}

pnode modify(pnode res, int b, int e, int l, int r, long long val) {
  if (!res) res = new node();

  if (b > r || e < l) return res;
  if (l <= b && e <= r) {
    assert(b == e);
    res->ans += val;
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
  if (!cur) return 0;

  if (b > r || e < l) return 0;
  if (l <= b && e <= r) return cur->ans;
  int mid = (b + e) >> 1;
  long long left = query(cur->left, b, mid, l, r);
  long long right = query(cur->right, mid + 1, e, l, r);
  return (left + right);
}

int main() {
#ifdef LOCAL
  freopen("g1.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  string line;
  cin >> line;
  stack<int> st;
  vector<int> match(line.size(), -1);

  int n = line.size();

  for (int i = 0; i < int(line.size()); i++) {
    if (line[i] == '(')
      st.push(i);
    else {
      if (st.size()) {
        match[i] = st.top();
        st.pop();
      }
    }
  }

  vector<vector<pair<int, int> > > queries(n);

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    queries[r].push_back(make_pair(l, i));
  }


  vector<int> sol(n);
  pnode root = NULL;
  vector<int> ans(q);
  for (int i = 0; i < n; i++) {
    if (match[i] != -1) {
      root = modify(root, 0, n - 1, match[i], match[i], 1);
    }
    for (int j = 0; j < int(queries[i].size()); j++) {
      int l = queries[i][j].first;
      int id = queries[i][j].second;
      ans[id] = query(root, 0, n - 1, l, i) * 2;
    }

  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
