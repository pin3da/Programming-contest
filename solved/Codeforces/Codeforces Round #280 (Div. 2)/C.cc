#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct entry {
  int a, b;
  entry(int x, int y) : a(x), b(y) {}
  bool operator < (const entry &o) const {
    if (b == o.b) return a < o.a;
    return b < o.b;
  }
};

int main() {
  long long n, t, avg;
  cin >> n >> t >> avg;
  multiset<entry> s;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    long long a, b; cin >> a >> b;
    s.insert(entry(a, b));
    sum += a;
  }
  long long need = avg * n - sum;
  long long ans = 0;
  while (need > 0) {
    auto cur = s.begin();
    long long give = t - cur-> a;
    if (give == 0) {
      s.erase(cur);
      continue;
    }
    if (give <= need) {
      need -= give;
      ans += give * cur-> b;
      s.erase(cur);
    } else {
      ans += need * cur-> b;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
