using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
  bool operator < (const point &o) const {
    if (x == o.x)
      return y < o.y;
    return x < o.x;
  }
  bool operator == (const point &o) const {
    return (x == o.x) && (y == o.y);
  }
};

inline
int cross(const point &a, const point &b, const point &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}


int visited[555];

void dfs(vector<point> &cool, vector<vector<int>> &g, int node) {
  if (visited[node])
    return;
  visited[node] = true;

  cout << " " << cool[node].x << " " << cool[node].y;

  for (int i = 0; i < g[node].size(); ++i) {
    dfs(cool, g, g[node][i]);
  }

}

void solve(int n) {
  vector<point> bounds;
  point p;
  map<pair<point, point>, int> seen;
  for (int i = 0; i < n; ++i) {
    vector<point> cur;
    for (int j = 0; j < 3; ++j) {
      cin >> p.x >> p.y;
      bounds.push_back(p);
      cur.push_back(p);
    }
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < j; ++k) {
        if (cur[j] < cur[k]) {
          seen[make_pair(cur[j], cur[k])]++;
        } else {
          seen[make_pair(cur[k], cur[j])]++;
        }
      }
    }
  }

  vector<vector<int>> g(seen.size() * 2);
  vector<point> cool;
  for (const auto &i : seen) {
    if (i.second == 1) {
      cool.push_back(i.first.first);
      cool.push_back(i.first.second);
    }
  }

  sort(cool.begin(), cool.end());
  cool.resize(unique(cool.begin(), cool.end()) - cool.begin());

  map<point, int> cod;
  point pivot = cool[0];
  for (int i = 0; i < cool.size(); ++i) {
    cod[cool[i]]  = i;
    if (cool[i].x == pivot.x) {
      if (cool[i].y < pivot.y)
        pivot = cool[i];
    } else if (cool[i].x < pivot.x)
      pivot = cool[i];
  }

  for (const auto &i : seen) {
    if (i.second == 1) {
       g[cod[i.first.first]].push_back(cod[i.first.second]);
       g[cod[i.first.second]].push_back(cod[i.first.first]);
       ///cout << i.first.first.x << " , " << i.first.first.y << " con " << i.first.second.x << " , " << i.first.second.y  << endl;
    }
  }


  //for (int i = 0; i < cool.size(); ++i) {
  //  cout << cool[i].x << " " << cool[i].y << " ";
  //}
  //
  // cout << pivot.x << " = " << pivot.y << endl;

  memset(visited, 0, sizeof visited);
  visited[cod[pivot]] = true;
  int a = g[cod[pivot]][0];
  int b = g[cod[pivot]][1];

  cout << pivot.x << " " << pivot.y;
  if (cross(cool[cod[pivot]], cool[a], cool[b]) > 0) {
    dfs(cool, g, b);
  } else {
    dfs(cool, g, a);
  }
  cout << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n != -1) {
    solve(n - 2);
  }
  return 0;
}

