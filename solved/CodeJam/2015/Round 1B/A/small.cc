using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int next(int a) {
  stringstream ss;
  ss << a;
  string line = ss.str();
  reverse(line.begin(), line.end());
  return atoi(line.c_str());
}

void solve() {
  int n;
  cin >> n;
  int cur = 1;
  int ans = 0;

  deque<pair<int, int> > q;
  vector<bool> visited(10000001);
  q.push_back(make_pair(1, 1));

  while (!q.empty()) {
    int cur = q.front().first;
    int dist = q.front().second;
    q.pop_front();
    if (cur == n) {
      cout << dist << endl;
      return;
    }
    if (visited[cur])
      continue;
    visited[cur] = true;

    int o1 = cur + 1;
    int o2 = next(cur);
    if (!visited[o1])
      q.push_back(make_pair(o1, dist + 1));
    if (!visited[o2])
      q.push_back(make_pair(o2, dist + 1));

  }
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
