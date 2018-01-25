#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int count(int a) {
  map<int, int> ans;
  deque<int> q;
  q.push_back(a);
  ans[a] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    if (cur == 1) continue;
    int x = cur >> 1;
    int y = cur - x;
    if (ans.count(x) == 0) {
      q.push_back(x);
      ans[x] = ans[cur] + 1;
    }
    if (ans.count(y) == 0) {
      q.push_back(y);
      ans[y] = ans[cur] + 1;
    }
  }
  return ans.size();
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));

  for (int i = 0; i < 100000; i++) {
    int a = random() % (int(1e9));
    if (count(a) > 100)
      cout << a << " " << count(a) << endl;
  }
  return 0;
}
