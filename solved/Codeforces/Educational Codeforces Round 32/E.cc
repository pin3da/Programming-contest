#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

vector<long long> get_sum(vector<long long> &a, vector<long long> &ind, long long mod) {
  long long total = 1 << ind.size();

  vector<long long> ans;
  for (int mask = 0; mask < total; mask++) {
    long long cur = 0;
    for (long long i = 0; i < (int)ind.size(); i++) {
      if ((mask >> i) & 1) {
        cur = (cur + a[ind[i]]) % mod;
      }
    }
    ans.push_back(cur);
  }
  return ans;
}

long long add(long long x, long long y, long long mod) {
  return (x + y) % mod;
}


void debug_vec(vector<long long> &a) {
  for (auto i : a) cout << i << " ";
  cout << endl;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> left, right;

  while (n < 4) {
    n++;
    a.push_back(0);
  }

  for (long long i = 0; i < n; i++) {
    if (i * 2 < n) left.push_back(i);
    else right.push_back(i);
  }

  vector<long long> first = get_sum(a, left, m);
  vector<long long> second = get_sum(a, right, m);
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  first.resize(unique(first.begin(), first.end()) - first.begin());
  second.resize(unique(second.begin(), second.end()) - second.begin());

  long long best = 0;
  for (int i = 0; i < (int)first.size(); i++) {
    long long target = (m - 1) - first[i];
    auto it = upper_bound(second.begin(), second.end(), target);
    if (it != second.begin()) {
      it--;
      best = max(first[i] + (*it), best);
    }
  }
  cout << best << endl;
  return 0;
}
