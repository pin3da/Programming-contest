#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double T;
typedef long double var;
const T pi = acos(-1);

T degree2radians(T g) {
  return g * pi / 180.0;
}

struct point {
  T lon, lat;
  point() {}
  point(T a, T b) : lon(a), lat(b) {}
};

T dista(const point point1, const point point2) {
  var EARTH_RADIUS = 6371.0;//in km
  var point1_lat_in_radians  = degree2radians( point1.lat );
  var point2_lat_in_radians  = degree2radians( point2.lat );
  var point1_long_in_radians  = degree2radians( point1.lon );
  var point2_long_in_radians  = degree2radians( point2.lon );

  return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
      cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
      cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}

struct dest {
  string name;
  point p;
  set<string> passions;
  dest () {}
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  set<string> people;
  for (int i = 0; i < n; ++i) {
    int m; cin >> m;
    for (int j = 0; j < m; ++j) {
      string line; cin >> line;
      people.insert(line);
    }
  }
  int y; cin >> y;
  vector<dest> all(y);
  for (int i = 0; i < y; ++i) {
    dest &cur = all[i];
    cin >> cur.name;
    cin >> cur.p.lat >> cur.p.lon;
    int z; cin >> z;
    for (int j = 0; j < z; ++j) {
      string line; cin >> line;
      cur.passions.insert(line);
    }
  }

  T best_dist = 1e100;
  pair<string, string> ans;
  int best_match = 0;
  for (int i = 0; i < y; ++i) {
    for (int j = i + 1; j < y; ++j) {
      T cost = dista(all[i].p, all[j].p);
      int cur = 0;
      for(auto &it : people) {
        if (all[i].passions.count(it) || all[j].passions.count(it))
          cur++;
      }
      if (cur > best_match) {
        ans = make_pair(all[i].name, all[j].name);
        best_match = cur;
        best_dist = cost;
      } else if (cur == best_match && cost < best_dist) {
        ans = make_pair(all[i].name, all[j].name);
        best_dist = cost;
      }
    }
  }
  if (ans.first > ans.second) swap(ans.first, ans.second);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
