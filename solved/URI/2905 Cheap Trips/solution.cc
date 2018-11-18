#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

long long dp[11234];
long long discount[] = {4, 2, 1, 1, 1, 1};

long long go(vector<long long> &du, vector<long long> &cost, int id) {
  if (id >= int(du.size())) return 0;

  if (dp[id] != -1) return dp[id];

  long long ans = 1LL << 60;
  long long partial_cost = 0;
  long long partial_duration = 0;

  for (int i = 0; partial_duration < 120 && i < 6 &&
                  (id + i) < int(du.size())
                ; i++) {
    partial_cost += cost[id + i] * discount[i];
    ans = min(ans, partial_cost + go(du, cost, id + i + 1));

    partial_duration += du[id + i];
  }

  return dp[id] = ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<long long> duration(n), cost(n);
  for (int i = 0; i < n; i++) {
    cin >> duration[i] >> cost[i];
  }

  memset(dp, -1, sizeof dp);
  long long ans = go(duration, cost, 0);
  string dec[] = {"00", "25", "50", "75"};
  cout << (ans >> 2) << "." << dec[ans & 3] << endl;
  return 0;
}
