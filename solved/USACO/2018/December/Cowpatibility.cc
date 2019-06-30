#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

// typedef pair<long long, long long> Hash;
typedef long long Hash;

const long long P1 = 3919;
const long long P2 = 14973817;

Hash getHash(vector<int> &a) {
  Hash result = 0;
  for (auto it : a) {
    result *= P2;
    result += it;
  }
  return result;
}

/*
Hash getHash(vector<int> &a) {
  Hash result;
  for (auto it : a) {
    result.first *= P1;
    result.first += it;

    result.second *= P2;
    result.second += it;
  }
  return result;
}
*/

vector<int> current;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  freopen("cowpatibility.in", "r", stdin);
  freopen("cowpatibility.out", "w", stdout);

  int n;
  cin >> n;

  unordered_map<Hash, long long> frec;

  long long total = (n * (n - 1)) / 2;
  current = vector<int>(5);
  vector<int> test(5);

  for (int i = 0; i < n; i++) {
    for (auto &it : current) cin >> it;
    sort(current.begin(), current.end());
    long long local = 0;
    for (int mask = 1; mask < (1 << 5); mask++) {
      int sig = (__builtin_popcount(mask) & 1) ? -1 : 1;
      test.clear();
      for (int j = 0; j < 5; j++) {
        if ((mask >> j) & 1) {
          test.emplace_back(current[j]);
        }
      }
      local += sig * frec[getHash(test)];
    }

    total += local;

    for (int mask = 1; mask < (1 << 5); mask++) {
      test.clear();
      for (int j = 0; j < 5; j++) {
        if ((mask >> j) & 1) {
          test.emplace_back(current[j]);
        }
      }
      frec[getHash(test)]++;
    }
  }
  cout << total << endl;
  return 0;
}
