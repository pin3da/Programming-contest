// http://codeforces.com/contest/217/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct point{
  int x, y;
};

const int MN = 100;
int pi[MN];

int fs(int x) {
  return (pi[x] == x) ? x : pi[x] = fs(pi[x]);
}

int js(int x, int y) {
  pi[fs(x)] = fs(y);
}


int main() {
  int n;
  cin >> n;
  vector<point> p(n);
  for (auto &i: p)
    cin >> i.x >> i.y;

  for (int i = 0; i < n; ++i)
    pi[i] = i;

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if ((p[i].x == p[j].x) || p[i].y == p[j].y)
        js(i, j);


  set<int> col;
  for (int i = 0; i < n; ++i)
    col.insert(fs(i));

  cout << col.size() - 1 << endl;

  return 0;
}
