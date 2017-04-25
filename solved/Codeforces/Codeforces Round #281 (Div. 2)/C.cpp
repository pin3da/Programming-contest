// http://codeforces.com/contest/493/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(vector<int> &all, vector<int> &a, vector<int> &b) {
  int i = 0, j = 0;

  long long best = -(1LL << 40);
  long long best_a, best_b;
  for (int k = 0; k < all.size(); ++k) {
    while (i < a.size() && a[i] <= all[k]) ++i;
    while (j < b.size() && b[j] <= all[k]) ++j;
    long long score_a = 2 * i + 3 * (a.size() - i);
    long long score_b = 2 * j + 3 * (b.size() - j);
    long long score = score_a - score_b;
    if (score > best) {
      best_a = score_a;
      best_b = score_b;
      best   = score;
    } else if (score == best) {
      if (score_a > best_a) {
        best_a = score_a;
        best_b = score_b;
        best   = score;
      }
    }
  }
  assert(best != -(1LL << 40));
  cout << best_a << ":" << best_b << endl;
}

int main() { ___

  int n, m;
  cin >> n;
  vector<int> a(n), all;
  all.push_back(0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    all.push_back(a[i]);
  }

  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    all.push_back(b[i]);
  }

  sort(all.begin(), all.end());
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  all.resize(distance(all.begin(), unique(all.begin(), all.end())));


  solve(all, a, b);

  return 0;
}