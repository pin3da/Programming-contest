// http://codeforces.com/contest/611/problem/B

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

vector<long long> zero;

void gen() {
  for (int i = 1; i < 62; ++i) {
    long long cur = (1LL << i) - 1;
    for (int j = 0; j < i - 1; ++j) {
      zero.push_back(cur ^ (1LL << j));
    }
  }
  sort(zero.begin(), zero.end());
  zero.resize(unique(zero.begin(), zero.end()) - zero.begin());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  gen();
  long long a, b;
  while (cin >> a >> b) {
    int ans = 0;
    for (int i = 0; i < zero.size(); ++i)
      if (zero[i] >= a && zero[i] <= b)
        ans++;

    cout << ans << endl;
  }

  return 0;
}
