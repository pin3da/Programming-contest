#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int N = 200011;  // limit for array size
int n;  // array size
long long t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

// Single modification, range query.
void modify(int p, long long value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

long long query(int l, int r) {  // max on interval [l, r)
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}


long long fill_dp(vector<pair<int, long long>> &data) {
  long long ans = 0;
  for (auto it : data) {
    long long best = query(0, it.first) + it.second;
    long long ant = query(it.first, it.first + 1);
    if (best > ant) {
      modify(it.first, best);
      ans = max(ans, best);
    }
  }
  return ans;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int m; cin >> m;
  vector<pair<int, int>> input(m);
  set<pair<int, int>> all;
  for (auto &i : input) {
    cin >> i.first >> i.second;
    all.insert(i);
  }
  map<pair<int, int>, int> order;
  int id = 0;
  for (auto it: all) order[it] = id++;

  vector<pair<int, long long>> data;
  for (auto it: input) {
    data.emplace_back(order[it], it.second - it.first + 1);
  }
  n = order.size() + 100;
  cout << fill_dp(data) << endl;

  return 0;
}
