#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif

struct point {
  long long x, y, h;
};

struct data {
    long long di, h;
    data(long long a, long long b) : di(a), h(b) {}
    bool operator < (const data &o ) const {
      if (di == o.di) return h < o.h;
      return di < o.di;
    }
};

long long mdist(point a, point b) {
  long long dx = a.x - b.x;
  long long dy = a.y - b.y;
  return dx * dx + dy * dy;
}


typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define STRICTLY_INCREASNG

int LIS(vector<int> &v) {
  VPII best;
    VI dad(v.size(), -1);

    for (int i = 0; i < int(v.size()); i++) {
  #ifdef STRICTLY_INCREASNG
      PII item = make_pair(v[i], 0);
      VPII::iterator it = lower_bound(best.begin(), best.end(), item);
      item.second = i;
  #else
      PII item = make_pair(v[i], i);
      VPII::iterator it = upper_bound(best.begin(), best.end(), item);
  #endif
      if (it == best.end()) {
        dad[i] = (best.size() == 0 ? -1 : best.back().second);
        best.push_back(item);
      } else {
        dad[i] = it == best.begin() ? -1 : prev(it)->second;
        *it = item;
      }
    }

    VI ret;
    for (int i = best.back().second; i >= 0; i = dad[i])
      ret.push_back(v[i]);
    reverse(ret.begin(), ret.end());
  return ret.size();
}

int LIS(vector<data> &a) {
  sort(a.begin(), a.end());
  vector<int> d;
  for (auto it : a) d.push_back(it.h);
  return LIS(d);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif


  point center;
  cin >> center.x >> center.y;
  int n; cin >> n;
  vector<point> all(n);
  map<pair<int, int>, vector<data>> slopes;
  for (int i = 0; i < n; i++) {
    cin >> all[i].x >> all[i].y >> all[i].h;
    long long dy = all[i].y - center.y;
    long long dx = all[i].x - center.x;
    long long g = __gcd(abs(dy), abs(dx));
    dy /= g;
    dx /= g;
    slopes[{dy, dx}].emplace_back(mdist(center, all[i]), all[i].h);
  }

  int ans = 0;
  for (auto &curr : slopes) {
    ans += LIS(curr.second);
  }
  cout << ans << endl;

  return 0;
}
