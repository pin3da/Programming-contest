#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

class Solution {
  struct Event {
    int x, open, y1, y2;
    Event() {}
    Event(int a, int b, int c, int d) :
      x(a),
      open(b),
      y1(c),
      y2(d)
    {}

    bool operator < (const Event &o) const {
      if (x == o.x)
        return open < o.open;
      return x < o.x;
    }
  };

  struct Active {

    multiset<pair<int, int>> all;

    void Add(int y1, int y2) {
      all.insert({y1, 1});
      all.insert({y2, -1});
    }

    void Erase(int y1, int y2) {
      all.erase(all.find({y1, 1}));
      all.erase(all.find({y2, -1}));
    }

    long long TotalActive() {
      int open = 0;
      long long last = 0, total = 0;

      for (auto it : all) {
        if (it.second > 0) {
          if (open == 0)
            last = it.first;
          open++;
        } else {
          open--;
          if (open == 0) {
            total += it.first - last;
          }
        }
      }
      return total;
    }
  };

  const long long mod = 1e9 + 7;

  public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    vector<Event> all_events;
    for (auto it : rectangles) {
      all_events.emplace_back(it[0], true, it[1], it[3]);
      all_events.emplace_back(it[2], false, it[1], it[3]);
    }

    sort(all_events.begin(), all_events.end());
    long long last = all_events[0].x;

    Active active;
    long long ans = 0;
    for (auto ev : all_events) {
      long long dx = ev.x - last;
      long long dy = active.TotalActive();
      long long area = (dx * dy) % mod;
      ans = (ans + area) % mod;

      last = ev.x;

      if (ev.open) {
        active.Add(ev.y1, ev.y2);
      } else {
        active.Erase(ev.y1, ev.y2);
      }
    }
    return ans;
  }
};

int main() {

  Solution sol;

  vector<vector<int>> rectangles(3);
  rectangles[0] = {0,0,2,2};
  rectangles[1] = {1,0,2,3};
  rectangles[2] = {1,0,3,1};

  long long area = sol.rectangleArea(rectangles);
  debug(area);
  assert(area == 6);

  rectangles[0] = {25,20,70,27};
  rectangles[1] = {68,80,79,100};
  rectangles[2] = {37,41,66,76};
  area = sol.rectangleArea(rectangles);
  debug(area);

  rectangles[0] = {2, 1, 4, 3};
  rectangles[1] = {5, 2, 7, 4};
  rectangles[2] = {7, 1, 9, 2};
  area = sol.rectangleArea(rectangles);
  debug(area);
  return 0;
}
