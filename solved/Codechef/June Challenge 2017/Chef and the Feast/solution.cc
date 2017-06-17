#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<int> all(n);
  for (int &i : all) cin >> i;

  vector<int> neg;
  long long sum_neg = 0, acc = 0, len = 0;
  for (int i = 0; i < n; ++i) {
    if (all[i] < 0) {
      neg.push_back(all[i]);
      sum_neg += all[i];
    } else {
      acc += all[i];
      len++;
    }
  }
  long long best = sum_neg + len * acc;
  sort(neg.rbegin(), neg.rend());
  for (int i = 0; i < (int)neg.size(); ++i) {
    long long next = sum_neg - neg[i] + (len + 1) * (acc + neg[i]);
    if (next > best) {
      sum_neg -= neg[i];
      len++;
      acc += neg[i];
      best = next;
    } else {
      break;
    }
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
