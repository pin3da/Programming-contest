/*
Solution for : CSES - Area of Rectangles
*/

#include <bits/stdc++.h>
using namespace std;
#define reu(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
typedef vector<int> vi;

/* Main solution */
int n;
struct Event {
  int x, y1, y2, val;

  bool operator<(const Event& other) const { return x < other.x; }
};
vector<Event> events;
const int MAX = 1e6;

class SegTree {
  int n;
  vi sum;
  vi cover;

  void update(int L, int R, int val, int p, int b, int e) {
	if (e < L || R < b || L > R) return;
	if (L <= b && e <= R) {
	  cover[p] += val;
	  if (cover[p] > 0) sum[p] = e - b + 1;
	  else if (b < e) sum[p] = sum[p << 1] + sum[(p << 1) | 1];
	  else sum[p] = 0;
	} else {
	  int mid = (b + e) >> 1;
	  update(L, R, val, p << 1, b, mid);
	  update(L, R, val, (p << 1) | 1, mid + 1, e);

	  if (cover[p] > 0) sum[p] = e - b + 1;
	  else sum[p] = sum[p << 1] + sum[(p << 1) | 1];
	}
  }

 public:
  SegTree(int n) : n(n), sum(4 * n + 4, 0), cover(4 * n + 4, 0) {}

  void update(int L, int R, int val) { update(L, R, val, 1, 0, n - 1); }

  int get() { return sum[1]; }
};

void Input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	events.push_back({x1, y1 + MAX, y2 + MAX, 1});
	events.push_back({x2, y1 + MAX, y2 + MAX, -1});
  }
}

void Solve() {
  sort(events.begin(), events.end());
  SegTree ST(2 * MAX + 1);
  ll ans = 0;
  for (int i = 0; i < (int)events.size() - 1; ++i) {
	ST.update(events[i].y1, events[i].y2 - 1, events[i].val);
	ans += 1ll * (events[i + 1].x - events[i].x) * ST.get();
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Input(), Solve();
  return 0;
}
