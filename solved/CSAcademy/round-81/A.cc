#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif

  int q;
  long long x;
  cin >> q >> x;

  vector<pair<int, int>> offers(q);
  for (auto &i : offers)
    cin >> i.first >> i.second;

  sort(offers.begin(), offers.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second - a.first == b.second - b.first) {
      return a.first < b.first;
    }
    return a.second - a.first > b.second - b.first;
  });

  int times = 12;

  while (times--) {
    for (auto of : offers) {
      if (of.second > of.first) {
        if (of.first <= x) {
          x += of.second - of.first;
          break;
        }
      }
    }
  }

  cout << x << endl;

  return 0;
}

