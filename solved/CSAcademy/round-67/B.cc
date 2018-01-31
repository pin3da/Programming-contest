#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<long long> pos, neg;
  for (int i = 0; i < n; i++) {
    long long t; cin >> t;
    if (t >= 0) pos.push_back(t);
    else neg.push_back(t);
  }

  long long total = accumulate(pos.begin(), pos.end(), 0LL);
  long long min_pos = 0;
  if (pos.size())
    min_pos = *min_element(pos.begin(), pos.end());
  long long max_neg = 0;
  if (neg.size())
    max_neg = *max_element(neg.begin(), neg.end());

  if (pos.size() == 0) {
    cout << 0 << endl;
  } else  {
    if (pos.size() & 1) {
      long long ans = 0;
      if (neg.size())
        ans = max(total - min_pos, total + max_neg);
      else
        ans = total - min_pos;
      cout << ans << endl;;
    } else {
      cout << total << endl;
    }
  }
  return 0;
}
