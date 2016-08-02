#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

int N;
long double weap[10];

map<long long, bool> dp;
long long base = 1000000;
int go(long double n) {
  if (n <= 1) return false;

  long long st = round(n * base);
  if (dp.count(st)) return dp[st];
  for (int i = 0; i < N; ++i)
    if (!go(n * weap[i])) return dp[st] = true;
  return dp[st] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc; cin >> tc;
  while (tc--) {
    long double x;
    cin >> x >> N;
    for (int i = 0; i < N; ++i) {
      cin >> weap[i];
    }
    sort(weap, weap + N);
    dp.clear();
    int win = go(x);
    puts(win ? "Nils" : "Mikael");
  }
  return 0;
}
