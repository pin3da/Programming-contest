#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 11; // size of alphabet
const int MS = 20001000; // Number of states.

long long pow_ten[19];

inline int mod_ten(int x) {
  if (x >= 10) return x - 10;
  return x;
}

struct trie{
  int tree[MS][MN];
  int nodes;
  vector<pair<int, int>> next; // val, i

  void clear(){
    memset(tree[nodes], -1, sizeof tree[nodes]);
    nodes++;
  }

  void init(){
    nodes = 0;
    clear();
  }

  void add(const string &s){
    int cur_node = 0;
    for(int i = 0; i < (int) s.size(); ++i){
      int id = s[i] - '0';
      if(tree[cur_node][id] == -1){
        tree[cur_node][id] = nodes;
        clear();
      }
      cur_node = tree[cur_node][id];
    }
  }

  long long query(string &s, int node, int id, int is_min) {
    if (id == (int)s.size()) return 0;
    int val = s[id] - '0';
    next.clear();
    for (int i = 0; i < 10; i++) {
      if (tree[node][i] != -1) {
        next.emplace_back(mod_ten(i + val), i);
      }
    }
    pair<int, int> b;
    if (is_min)
      b = *min_element(next.begin(), next.end());
    else
      b = *max_element(next.begin(), next.end());

    int to = b.second;
    long long cur = b.first * pow_ten[s.size() - id - 1];;
    long long ans = query(s, tree[node][to], id + 1, is_min);
    return cur + ans;
  }
};


trie tree;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  pow_ten[0] = 1;
  for (int i = 1; i < 19; i++) {
    pow_ten[i] = pow_ten[i - 1] * 10LL;
  }

  int n; cin >> n;
  vector<string> all(n);
  int max_len = 0;
  for (int i = 0; i < n; i++) {
    cin >> all[i];
    max_len = max<int>(max_len, all[i].size());
  }

  for (int i = 0; i < n; i++) {
    string next(max_len, '0');
    int start = max_len - all[i].size();
    for (int j = 0; j < (int) all[i].size(); j++) {
      next[start + j] = all[i][j];
    }
    all[i] = move(next);
  }

  tree.init();
  tree.add(all[0]);

  long long best_min = numeric_limits<long long>::max();
  long long best_max = 0;
  for (int i = 1; i < n; i++) {
    long long a = tree.query(all[i], 0, 0, true);
    long long b = tree.query(all[i], 0, 0, false);
    best_min = min(best_min, a);
    best_max = max(best_max, b);
    tree.add(all[i]);
  }
  cout << best_min << " " << best_max << endl;
  return 0;
}
