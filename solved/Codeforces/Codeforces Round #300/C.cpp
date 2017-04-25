// http://codeforces.com/contest/538/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct entry{
  long long d, h;
};

const string imp = "IMPOSSIBLE";

void solve(long long n, int m) {
  vector<entry> a(m);
  for (auto &i : a) cin >> i.d >> i.h;

  long long best = a[0].h + a[0].d - 1;
  for (int i = 1; i < m; ++i) {
    long long delta = llabs(a[i].h - a[i - 1].h);
    long long dist = a[i].d - a[i - 1].d;
    if (dist < delta)  {
      cout << imp << endl;
      return;
    }
    dist -= delta;
    best = max(best, (dist >> 1) + max(a[i].h, a[i - 1].h));
  }
  long long last_dist = n - a.back().d;
  best = max(best, a.back().h + last_dist);
  cout << best  << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m; while (cin >> n >> m) solve(n, m);
  return 0;
}
