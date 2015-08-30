using namespace std;
#include <bits/stdc++.h>

struct entry{
  int t, p, s;
  entry() {}
  entry(int a, int b, int c) : t(a), p(b), s(c) {}
};

map<string, int> cod;

int rate;
const int MN = 111;
int dp[MN][MN][MN * MN];
int go(vector<entry> &a, int i, int g, int s) {
  if (i == a.size())
    return 0;

  if (dp[i][g][s] != -1)
    return dp[i][g][s];

  int best = go(a, i + 1, g, s);
  if (a[i].t == 0) {
    if (s >= a[i].s) {
      best = max(best, 1 + go(a, i + 1, g, s - a[i].s));
      if (rate == a[i].s && g)
        best = max(best, 1 + go(a, i + 1, g + 1, s));
    } else if (g) {
      int ds = ((rate - a[i].s + a[i].p - 1) / a[i].p) * a[i].p;
      best = max(best, 1 + go(a, i + 1, g - 1, s +  ds));
    }
  }
  if (a[i].t == 1) {
    if (s >= a[i].s)
      best = max(best, 1 + go(a, i + 1, g, s - a[i].s));
    if (g) {
      int ds = round(double(rate - a[i].s) / (double)a[i].p) * a[i].p;
      best = max(best, 1 + go(a, i + 1, g - 1, s + ds));
    }
  }
  if (a[i].t == 2) {
    if (s >= a[i].s)
      best = max(best, 1 + go(a, i + 1, g, s - a[i].s));
    if (g) {
      int ds = ((rate - a[i].s) / a[i].p) * a[i].p;
      best = max(best, 1 + go(a, i + 1, g - 1, s + ds));
    }
  }
  return dp[i][g][s] = best;
}

int main() {
  cod["generous"] = 0; cod["honest"] = 1; cod["greedy"] = 2;
  int c, n;
  cin >> rate >> c >> n;
  string line;
  int p, s;
  vector<entry> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> line >> p >> s;
    a[i] = entry(cod[line], p, s);
  }
  memset(dp, -1, sizeof dp);
  cout << go(a, 0, c, 0) << endl;
  return 0;
}
