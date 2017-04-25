// http://codeforces.com/contest/92/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  string line;
  while (cin >> line) {
    reverse(line.begin(), line.end());
    deque<int> q(line.size());
    for (int i = 0; i < line.size(); ++i) q[i] = line[i] - '0';
    int ans = 0;
    while (!q.empty()) {
      if (q.size() == 1) break;
      if (q.front() == 0) q.pop_front();
      else {
        int carry = 1;
        for (int i = 0; i < q.size(); ++i) {
          if (carry + q[i] <= 1) {
            q[i] = carry + q[i];
            carry = 0;
            break;
          }
          q[i] = 0;
          carry = 1;
        }
        if (carry)
          q.push_back(1);
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
