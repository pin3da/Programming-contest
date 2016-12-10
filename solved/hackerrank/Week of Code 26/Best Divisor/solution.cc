#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct item {
  int val, score;
  item () {}
  item (int a) : val(a) {
    score = 0;
    while (a > 0) {
      score += a % 10;
      a /= 10;
    }
  }
  bool operator < (const item &o) const {
    if (score == o.score) {
      return val > o.val;
    }
    return score < o.score;
  }
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  priority_queue<item> ans;
  int n; cin >> n;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    ans.push(item(i));
    ans.push(item(n / i));
  }
  cout  << ans.top().val << endl;
  return 0;
}
