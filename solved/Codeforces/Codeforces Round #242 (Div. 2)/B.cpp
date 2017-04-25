// http://codeforces.com/contest/424/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int million = 1000000;

struct city{
  long long x, y, k;
  long long dist;
  city() {}
  city(long long a, long long b, long long c) : x(a) , y(b), k (c) {
    dist = x * x + y * y;
  }

  bool operator < (const city &o) const {
    return dist < o.dist;
  }
};

int main() { ___
  int n;
  long long s;
  cin >> n >> s;
  vector<city> c(n);
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    c[i] = city(x,y,z);
  }

  sort(c.begin(), c.end());

  long long dist = 0;
  int found = 0;
  for (int i = 0; i < n and !found; ++i) {
    s += c[i].k;
    dist = max(dist, c[i].dist);
    if (s >= million)
      found = true;
  }

  if (!found)
    cout << -1 << endl;
  else
    cout << setprecision(10) << sqrt(dist) << endl;


  return 0;
}