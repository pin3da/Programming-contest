#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct st {
  int s;
  int d;
  st (int a, int b) : s(a), d(b) {}
};

int add(int a) {
  return a + 1;
}

int reverse(int a) {
  string b = to_string(a);
  reverse(b.begin(), b.end());
  return atoi(b.c_str());
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int start, target;
    cin >> start >> target;

    queue<st> q;
    q.push(st(start, 0));
    int ans = -1;
    unordered_set<int> seen;
    while (!q.empty()) {
      int cur = q.front().s;
      int dist = q.front().d;
      q.pop();

      if (seen.count(cur)) continue;
      seen.insert(cur);
      if (cur == target) {
        ans = dist;
        break;
      }

      q.push(st(add(cur), dist + 1));
      q.push(st(reverse(cur), dist + 1));
    }

    assert(ans != -1);
    cout << ans << endl;
  }
  return 0;
}
