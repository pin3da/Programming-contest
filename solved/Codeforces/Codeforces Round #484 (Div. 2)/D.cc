#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct my_set{

  map<int, int> frec;

  void erase(int val) {
    frec[val]--;
    if (frec[val] == 0)
      frec.erase(val);
  }

  void insert(int val) {
    frec[val]++;
  }

  int different() {
    return frec.size();
  }

  int locations() {
    assert(frec.size() == 1);
    return frec.begin()->second;
  }
};


const int MN = 1e5 + 100;
int P[MN];
int SZ[MN];

void init(int x) {
  SZ[x] = 1;
  P[x] = x;
}

int find_set(int x) {
  return P[x] == x ? x : P[x] = find_set(P[x]);
}

void joint(int x, int y) {
  int px = find_set(x), py = find_set(y);
  SZ[px] += SZ[py];
  P[py] = px;
}

int get_size(int x) {
  return SZ[find_set(x)];
}

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  my_set sizes;
  vector<int> group(n, -1);

  int ans = 0;
  int best_locations = 0;
  for (auto it : a) {
    int val = it.first;
    int pos = it.second;

   // debug(pos, val);

    init(pos);
    sizes.insert(1); // my size

    /*
    cerr << "----before---" << endl;
    for (auto it : sizes.frec) {
      debug(it.first, it.second);
    }
    cerr << endl;
    */

    if (pos > 0 && group[pos - 1] != -1) {
      sizes.erase(get_size(pos - 1));
      sizes.erase(get_size(pos));
      joint(pos, pos - 1);
      sizes.insert(get_size(pos));
      // debug("joint", pos, pos - 1);
    }

    if (pos + 1 < n && group[pos + 1] != -1) {
      sizes.erase(get_size(pos + 1));
      sizes.erase(get_size(pos));
      joint(pos, pos + 1);
      sizes.insert(get_size(pos));
    }

    group[pos] = 666;

    /*
    cerr << "---after---" << endl;
    for (auto it : sizes.frec) {
      debug(it.first, it.second);
    }
    cerr << endl;
    */

    if (sizes.different() == 1) { // len of locations
      int cur_locations = sizes.locations();
      if (cur_locations > best_locations) {
        ans = val;
        best_locations = cur_locations;
      }
    }
  }

  cout << ans + 1 << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

