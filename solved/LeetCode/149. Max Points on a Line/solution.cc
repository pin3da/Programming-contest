#include <vector>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  long long gcd(long long x, long long y) {
    if (y > x) swap(x, y);
    while (y > 0) {
      x %= y;
      swap(x, y);
    }
    return x;
  }

  public:
  int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (n < 2)
      return n;

    int best = 2;
    for (int i = 0; i < n; i++) {
      map<pair<long long, long long>, int> frec;
      int extra = 0;
      for (int j = 0; j < n; j++) {
        if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
          extra++;
        else {
          long long dx = (long long)(points[i].x) - points[j].x;
          long long dy = (long long)(points[i].y) - points[j].y;
          long long g = gcd(abs(dx), abs(dy));
          dx /= g;
          dy /= g;
          frec[{dy, dx}]++;
        }
      }
      best = max(best, extra);
      for (auto it : frec)
        best = max(best, it.second + extra);
    }
    return best;
  }
};

int main() {

  Solution sol;
  vector<Point> points = {Point(0, 0), Point(1, 65536), Point(65536, 0)};
  assert(2 == sol.maxPoints(points));


  return 0;
}
