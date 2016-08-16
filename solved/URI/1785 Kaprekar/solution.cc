#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

deque<int> toss(int a) {
  deque<int> ans;
  while (a) {
    ans.push_front(a % 10);
    a /= 10;
  }
  while (ans.size() < 4) ans.push_front(0);
  return ans;
}

int same(int a) {
  deque<int> q = toss(a);
  for (int i = 1; i < q.size(); ++i)
    if (q[i] != q[i - 1]) return false;
  return true;
}

int to_num(deque<int> &a) {
  int b = 0;
  for (int i = 0; i < a.size(); ++i)
    b = b * 10 + a[i];
  return b;
}

void solve() {
  int a; cin >> a;
  if (same(a))
    cout << -1 << endl;
  else {
    int ans = 0;
    while (a != 6174) {
      deque<int> q = toss(a);
      sort(q.rbegin(), q.rend());
      int hi = to_num(q);
      sort(q.begin(), q.end());
      int lo = to_num(q);
      a = hi - lo;
      ans++;
    }
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Caso #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
