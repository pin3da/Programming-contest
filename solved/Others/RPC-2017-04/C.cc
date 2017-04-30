#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

struct point {
  long long x, y;
  int id;
  point() {}
  point(long long a, long long b) : x(a), y(b) {}
  double dist(point &o) {
    long long a = x - o.x;
    long long b = y - o.y;
    return sqrt(a * a + b * b);
  }
};


vector<int> solve(vector<point> &a, int start, int end, int inc) {
  vector<int> ans(a.size());
  deque<pair<int, int>> q;
  for (int i = start; i != end; i += inc) {
    if (q.size() == 0) {
      q.emplace_back(a[i].y, i);
    } else {
      while (q.back().first <= a[i].y) {
        q.pop_back();
      }
      ans[i] = q.back().second;
      q.emplace_back(a[i].y, i);
    }

  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin >> n;
  vector<point> a(n + 2);
  int j = 0;
  for (auto &i : a) {
    cin >> i.x >> i.y;
    i.id = j;
    j++;
  }

  cout << fixed << setprecision(4);
  vector<int> left = solve(a, 0, n + 1, 1);
  vector<int> right = solve(a, n + 1, 0, -1);
  for (int i = 1; i < n + 1; ++i) {
    cout << left[i] << " " << right[i] << " " << a[i].dist(a[left[i]]) << " " << a[i].dist(a[right[i]]) << endl;
  }
  return 0;
}
