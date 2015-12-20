using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct tree{
  vector<int> r, l;
  vector<int> val;
  tree(int n) {
    r.resize(n);
    l.resize(n);
    val.resize(n);
  }

  void flatten(vector<vector<int>> &g, vector<int> &v, int start, int &ts) {
    deque<int> st;
    st.push_back(start);
    vector<bool> vi(g.size());
    while (!st.empty()) {
      int node = st.back();
      if (vi[node]) {
        r[node] = ts - 1;
        st.pop_back();
      } else {
        l[node] = ts;
        val[ts] = v[node];
        ts++;
        vi[node] = true;
        for (int i = 0; i < g[node].size(); ++i) {
          st.push_back(g[node][i]);
        }
      }
    }
  }
};



typedef int ll;
const ll inf = 1LL << 30;

struct Segment_tree{
  vector<ll> M;
  vector<ll> pending;
  int type;

  Segment_tree(int n, int is_max = 0){
    M.resize((n << 2) + 4);
    pending.resize((n << 2) + 4);
    type = is_max;
  }

  void init(vector<ll> &A, int node, int a, int b) {
    if (a == b) {
      M[node] = A[a];
      pending[node] = 0LL;
    } else {
      init(A, node << 1, a, (a + b) >> 1);
      init(A, node << 1 | 1 ,((a + b) >> 1)+1, b);
      if (type)
        M[node] = max(M[node << 1], M[node << 1 | 1]);
      else
        M[node] = min(M[node << 1], M[node << 1 | 1]);
    }
  }


  void propagate(int node, int a, int b) {
    if (a == b) {
      M[node] += pending[node];
      pending[node] = 0LL;
      return;
    }
    M[node] += pending[node];
    pending[node << 1] += pending[node];
    pending[node << 1 | 1] += pending[node];
    pending[node] = 0LL;
  }

  ll query(int node, int a, int b, int i, int j){
    propagate(node, a, b);
    if(a > j or b < i) {
      if (type) return 0;
      return inf;
    }

    if(a >= i and b <= j)
      return M[node];
    ll p1 = query(node << 1, a, (a + b) >> 1, i, j);
    ll p2 = query(node << 1 | 1,((a + b) >> 1) + 1, b, i, j);

    if (type)
      return max(p1, p2);
    return min(p1, p2);

  }


  void update(int node, int a, int b, ll value, int i, int j) {
    propagate(node, a, b);
    if (b < i or a > j) return;
    if (a >= i and  b <= j) {
      M[node] +=  value;
      pending[node << 1] +=  value;
      pending[node << 1 | 1] +=  value;
      return;
    }

    //propagate(node,a,b);
    update(node << 1, a, (a + b) >> 1, value, i, j);
    update(node << 1 | 1, ((a + b) >> 1) + 1 , b, value, i, j);

    if (type)
      M[node] = max(M[node << 1], M[node << 1 | 1]);
    else
      M[node] = min(M[node << 1], M[node << 1 | 1]);
  }
};

const int MN = 1000000 + 100;


void solve() {
  int n, tmp; scanf("%d", &n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &tmp);
    tmp--;
    g[tmp].push_back(i);
  }
  vector<int> v(n);
  for (auto &i : v) {
    // cin >> i;
    scanf("%d", &i);
  }

  int ts = 0;

  tree t(n);
  t.flatten(g, v, 0, ts);

  int q; scanf("%d", &q);


  vector<ll> &A = t.val;
  Segment_tree tree_min(n * 2), tree_max(n * 2, true);
  tree_min.init(A, 1, 0, A.size() - 1);
  tree_max.init(A, 1, 0, A.size() - 1);


  for (int i = 0; i < q; ++i) {
    char op[3];
    int a, b;
    scanf("%s %d", op, &a);
    //cin >> op >> a;
    if (op[0] == 'R') {
      // cin >> b;
      scanf("%d", &b);
      int l = t.l[a - 1], r = t.r[a - 1];
      /*vector<long long> &val = t.val;
      for (int j = l; j <= r; ++j) {
        val[j] += b;
      }*/
      tree_min.update(1, 0, A.size() - 1, b, l, r);
      tree_max.update(1, 0, A.size() - 1, b, l, r);
    } else {
      int l = t.l[a - 1], r = t.r[a - 1];
      /*vector<long long> &val = t.val;
      long long mmin = val[l], mmax = val[r];
      for (int j = l; j <= r; ++j) {
        mmin = min(mmin, val[j]);
        mmax = max(mmax, val[j]);
      }*/

      long long mmax = tree_max.query(1, 0, A.size() - 1, l, r);
      long long mmin = tree_min.query(1, 0, A.size() - 1, l, r);
#ifdef MIO
      printf("%lld\n", mmax - mmin);
#else //Codeforces stuff
      printf("%I64d\n", mmax - mmin);
#endif
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; scanf("%d", &tc);
  //cin >> tc;
  for (int i = 0; i < tc; ++i) solve();
  return 0;
}
