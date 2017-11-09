#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct point {
  int x, y;
  bool operator <(const point &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};


int get_best(vector<point> &s, set<point> &all, int &best) {
  for (int i = 0; i < (int)s.size(); i++) {
    auto first = s[i];
    for (int j = i + 1; j < (int)s.size(); j++) {
      auto second = s[j];
      if (first.x == second.x) {
        int dy = abs(first.y - second.y);
        if (dy < best) continue;
        point p = {first.x + dy, first.y};
        point q = {second.x + dy, second.y};
        if (all.count(p) && all.count(q)) {
          best = max(best, dy);
        }
        p = {first.x - dy, first.y};
        q = {second.x - dy, second.y};
        if (all.count(p) && all.count(q)) {
          best = max(best, abs(dy));
        }
      } else {
        int dx = abs(first.x - second.x);
        if (dx < best) continue;
        point p = {first.x, first.y + dx};
        point q = {second.x, second.y + dx};
        if (all.count(p) && all.count(q)) {
          best = max(best, dx);
        }
        p = {first.x, first.y - dx};
        q = {second.x, second.y - dx};
        if (all.count(p) && all.count(q)) {
          best = max(best, abs(dx));
        }
      }
    }
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  while(cin >> n) {

    map<int, vector<point>> data[2];
    set<point> all;

    map<int, int> frec[2];

    for (int i = 0; i < n; i++) {
      point t;
      cin >> t.x >> t.y;
      all.insert(t);
      frec[0][t.x]++;
      frec[1][t.y]++;
    }
    for (auto it: all) {
      if (frec[0][it.x] < frec[1][it.y]) {
        data[0][it.x].push_back(it);
      } else {
        data[1][it.y].push_back(it);
      }
    }
    int best = 0;
    for (int i = 0; i < 2; i++) {
      for (auto it : data[i]) {
        best = max(best, get_best(it.second, all, best));
      }
    }
    cout << best << endl;
  }
  return 0;
}
