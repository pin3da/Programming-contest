#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

const int MN = 1000000 + 100;

int divs[MN];

void fill_divs() {
  for (int i = 1; i < MN; i++) {
    for (int j = i; j < MN; j += i) {
      divs[j]++;
    }
  }
}


const int MVAL = 300000 + 100;
const int ML = 10;

struct seg_tree {
  long long sum[(MVAL << 2) + 4];
  int pending[(MVAL << 2) + 4];
  int tot[(MVAL << 2) + 4];
  int len;

  seg_tree(vector<int> &a) {
    len = a.size();
    init(a, 1, 0, a.size() - 1);
    memset(pending, 0, sizeof pending);
    memset(tot, 0, sizeof tot);
  }

  void update(int node) {
    sum[node] = sum[node << 1] + sum[node << 1 | 1];
  }

  void init(vector<int> &a, int node, int b, int e) {
    if (b == e) {
      sum[node] = a[b];
    } else {
      int mid = (b + e) >> 1;
      init(a, node << 1, b, mid);
      init(a, node << 1 | 1, mid + 1, e);

      update(node);
    }
  }

  void push_down(int node, int b, int e) {
    while (tot[node] < ML && pending[node] > 0) {
      pending[node]--;
      if (b < e) {
        pending[node << 1]++;
        pending[node << 1 | 1]++;
        int mid = (b + e) >> 1;
        push_down(node << 1, b, mid);
        push_down(node << 1 | 1, mid + 1, e);
        update(node);
      } else {
        sum[node] = divs[sum[node]];
      }
      tot[node]++;
    }
  }

  void modify(int node, int b, int e, int l, int r) {
    push_down(node, b, e);
    if (b > r || e < l) return;

    if (b >= l && e <= r) {
      pending[node]++;
      push_down(node, b, e);
      return;
    }

    int mid = (b + e) >> 1;
    modify(node << 1, b, mid, l, r);
    modify(node << 1 | 1, mid + 1, e, l, r);
    update(node);
  }

  long long query(int node, int b, int e, int l, int r) {
    push_down(node, b, e);

    if (b > r || e < l) return 0;
    if (b >= l && e <= r) {
      return sum[node];
    }

    int mid = (b + e) >> 1;
    return query(node << 1, b, mid, l, r) + query(node << 1 | 1, mid + 1, e, l, r);
  }

  void modify(int l, int r) {
    modify(1, 0, len - 1, l, r);
  }

  long long query(int l, int r) {
    return query(1, 0, len - 1, l, r);
  }
};


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  fill_divs();

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &i : a) cin >> i;

  seg_tree tree(a);

  while (m--) {
    int p, l, r;

    cin >> p >> l >> r;
    l--, r--;
    if (p == 1) {
      tree.modify(l, r);
    } else {
      cout << tree.query(l, r) << endl;
    }
  }

  return 0;
}
