#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
const int MN = 300123;

struct binary_index_tree {
  int n;
  int t[MN + 10];

  binary_index_tree(int x) : n(x + 5) {}

  void add(int where, long long what){
    for (where++; where <= n; where += where & -where){
      t[where] += what;
    }
  }

  void add(int from, int to, long long what) {
    add(from, what);
    add(to + 1, -what);
  }

  long long query(int where){
    long long sum = t[0];
    for (where++; where > 0; where -= where & -where){
      sum += t[where];
    }
    return sum;
  }

  long long query(int from, int to) {
    assert(from <= to);
    long long sum = query(to);
    if (from > 0) return sum - query(from - 1);
    return sum;
  }
};

int update_last(binary_index_tree &tree, int last) {
  for (int i = 0; i < last; i++) {
    if (tree.query(i, last) == (last - i + 1))
      return i;
  }
  return last;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  binary_index_tree tree(n);

  int ans = 1, last = n;
  tree.add(n, 1);
  cout << ans << ' ';
  for (int i = 0; i < n; i++) {
    int pos; cin >> pos; pos--;
    tree.add(pos, 1);

    last = update_last(tree, last);
    if (pos >= last) {
      ans = max(1, ans - (pos - last));
    } else {
      ans += 1;
    }

    if (i) cout << ' ';
    cout << ans;
  }
  cout << endl;
  return 0;
}
