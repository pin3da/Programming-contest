#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct event {
  int time, type, id;
  event() {}
  event(int a, int b, int c) : time(a), type(b), id(c) {}
  bool operator < (const event &o) const {
    if (time == o.time) {
      if (type  == o.type) return id < o.id;
      return type < o.type;
    }
    return time < o.time;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<event> a;a.reserve(2 * n);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      a.emplace_back(t, 0, i);
      cin >> t;
      a.emplace_back(t, 1, i);
    }
    sort(a.begin(), a.end());
    set<int> open;
    int ans = 0;
    for (auto &e : a) {
      if (e.type == 1 && open.count(e.id)) { // close
        open.clear();
        ans++;
      } else {
        open.insert(e.id);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
