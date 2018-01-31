#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << h;
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif


const int MN = 10000 + 100;

int sum(int n) {
  int ans = 0;
  while (n) {
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int k;
  cin >> k;

  vector<int> small;
  int cur = 0;
  while (small.size() < MN) {
    if (sum(cur) == 10) small.push_back(cur);
    cur++;
  }

  cout << small[k - 1] << endl;

  return 0;
}
