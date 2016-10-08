#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e5 + 100;
string a;
struct seg_tree {
  int n;  // array size
  int t[5 * MN];

  int build(int node, int b, int e) {
    if (b == e) {
      return t[node] = b;
    }
    int m = (b + e) >> 1;
    int a1 = build(node << 1, b, m);
    int a2 = build(node << 1 | 1, m + 1, e);
    if (a[a1] < a[a2])
      t[node] = a1;
    else
      t[node] = a2;
    return t[node];
  }

  int query(int node, int i, int j, int b = 0, int e = a.size() - 1) {
    if (b > j || e < i) return -1;
    if (b >= i && e <= j) {
      return t[node];
    }

    int m = (b + e) >> 1;
    int o1 = query(node << 1, i, j, b, m);
    int o2 = query(node << 1 | 1, i, j, m + 1, e);
    int best = -1;
    if (o1 != -1) {
      best = o1;
      if (o2 != -1) {
        if (a[o1] < a[o2]) {
          best = o1;
        } else {
          best = o2;
        }
      }
    } else if (o2 != -1) {
      best = o2;
    }
    return best;
  }

};

seg_tree tree;

int choosed[MN];

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  size_t m;
  string line;
  while (cin >> m >> line) {
    size_t i = 0;
    string ans;
    a = line;
    tree.n = line.size();
    memset(tree.t, -1, sizeof tree.t);
    tree.build(1, 0, line.size() - 1);

    set<char> seen;
    memset(choosed, 0, sizeof choosed);
    while (i < line.size()) {
      size_t to = min(line.size() - 1, i + m - 1);
      size_t best = tree.query(1, i, to);

      /*
         size_t best = to;
         for (int j = to; j >= int(i); --j) {
         if (line[j] < line[best])
         best = j;
         }*/

      ans.push_back(line[best]);
      seen.insert(line[best]);
      choosed[best] = true;
      i = best + 1;
      if (line.size() - best <= m) {
        break;
      }
    }
    char last = *(--seen.end());
    for (size_t i = 0; i < line.size(); ++i) {
      if (!choosed[i] && line[i] < last)
        ans.push_back(line[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
  }

  return 0;
}
