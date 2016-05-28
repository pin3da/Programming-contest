#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;


int K;

const int MN = 222;
double memo[MN][MN];
double prob(deque<double> &p, int i, int q) {
  if (p.size() == i) {
    if (q * 2 == K) return 1;
    return 0;
  }
  if (memo[i][q] > -0.5) return memo[i][q];
  double ans = prob(p, i + 1, q + 1) * p[i] + prob(p, i + 1, q) * (1.0 - p[i]);
  return memo[i][q] = ans;
}


double comp(deque<double> &p, int &mask, int i, int q) {
  if (p.size() == i) {
    if (q * 2 == K) return 1;
    return 0;
  }
  if (((mask >> i) & 1) == 0) return comp(p, mask, i + 1, q);
  double ans = comp(p, mask, i + 1, q + 1) * p[i] + comp(p, mask, i + 1, q) * (1.0 - p[i]);
  return ans;
}

double brute(deque<double> &p) {
  int top = 1 << p.size();
  double best = 0;
  int best_mask;
  for (int mask = 0; mask < top; ++mask) {
    if (__builtin_popcount(mask) == K) {
      // best = max(best, comp(p, mask, 0, 0));
      if (comp(p, mask, 0, 0) > best) {
        best = comp(p, mask, 0, 0);
        best_mask = mask;
      }
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    if ((best_mask >> i) & 1)
      cout << p[i] << " ";
  }
  cout << endl;
  return best;
}

void clean_memo() {
  for (int i = 0; i < MN; ++i)
    for (int j = 0; j < MN; ++j)
      memo[i][j] = -2;
}

double go(deque<double> &p) {
  sort(p.begin(), p.end());
  deque<double> window;
  for (int i = 0; i < K; ++i)
    window.push_back(p[i]);

  clean_memo();
  double best = prob(window, 0, 0);
  for (int i = K; i < p.size(); ++i) {
    window.pop_front();
    window.push_back(p[i]);
    clean_memo();
    best = max(best, prob(window, 0, 0));
  }
  window.clear();
  for (int i = 0; i < K; ++i) {
    window.push_front(p[i]);
  }
  clean_memo();
  best = max(best, prob(window, 0, 0));
  for (int i = 0; i < K; ++i) {
    window.pop_front();
    window.push_back(p[p.size() -  1 - i]);
    clean_memo();
    best = max(best, prob(window, 0, 0));
  }
  return best;
}

void solve() {
  int n;
  cin >> n >> K;
  deque<double> p(n);
  for (auto &i: p) cin >> i;
  cout << go(p) << endl;
  // cout << brute(p) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
