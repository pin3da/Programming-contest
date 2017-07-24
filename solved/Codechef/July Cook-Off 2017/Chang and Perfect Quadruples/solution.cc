#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007LL;

long long add(long long x, long long y) {
  x %= mod;y %= mod;
  return (x + y) % mod;
}

long long mult(long long x, long long y) {
  x %= mod;y %= mod;
  return (x * y) % mod;
}


struct DS_MAX {

  map<long long, long long> frec;
  long long total = 0;

  void add_x(long long x) {
    while (frec.size()) {
      auto it = frec.begin();
      long long first = it-> first;
      if (first < x) {
        total += (x - first) * it-> second;
        frec[x] += it-> second;
        frec.erase(it);
      } else {
        break;
      }
    }
    frec[x]++;
    total += x;
  }

  long long get_sum() {
    return total;
  }
};


struct DS_MIN {

  map<long long, long long> frec;
  long long total = 0;

  void add_x(long long x) {
    while (frec.size()) {
      auto it = (--frec.end());
      long long first = it-> first;
      if (first > x) {
        total += (x - first) * it-> second;
        frec[x] += it-> second;
        frec.erase(it);
      } else {
        break;
      }
    }
    frec[x]++;
    total += x;
  }

  long long get_sum() {
    return total;
  }
};


long long solve_brute(vector<long long> &data) {
  int n = data.size();
  long long ans = 0;
  long long inf = 10000000000LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (i <= j && j < k && k <= l) {
              long long left = 0, right = inf;
              for (int x = i; x <= j; x++)
                left = max(left, data[x]);
              for (int x = k; x <= l; x++)
                right = min(right, data[x]);
              ans += (left * right) % mod;
              ans %= mod;
          }
        }
      }
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;

  vector<long long> data(n);

  for (int i = 0; i < n; ++i)
    cin >> data[i];

  DS_MAX ds_max;
  DS_MIN ds_min;

  vector<long long> pref(n), suff(n);
  for (int i = 0; i < n; ++i) {
    ds_max.add_x(data[i]);
    pref[i] = ds_max.get_sum();
  }

  for (int i = n - 1; i >= 0; --i) {
    ds_min.add_x(data[i]);
    suff[i] = ds_min.get_sum();
    if (i < (n - 1))
      suff[i] = add(suff[i], suff[i + 1]);
  }


  long long ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    ans = add(ans, mult(pref[i], suff[i + 1]));
  }
   cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
