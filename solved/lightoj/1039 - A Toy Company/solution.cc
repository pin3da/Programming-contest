using namespace std;
#include <bits/stdc++.h>

bool valid(vector<vector<string> > &c, const string &w) {
  for (int i = 0; i < c.size(); ++i) {
    int bad = true;
    for (int j = 0; j < 3; ++j)
      if (c[i][j].find(w[j]) == string::npos)
        bad = false;
    if (bad)
      return false;
  }
  return true;
}

char add(char c) {
  int a = c - 'a';
  a = (a + 1) % 26;
  return a + 'a';
}

char sub(char c) {
  int a = c- 'a';
  a = (a + 25) % 26;
  return a+ 'a';
}

void solve() {
  string from, to;
  cin >> from >> to;
  int c;
  cin >> c;
  vector<vector<string> > ct(c, vector<string>(3));
  for (int i = 0; i < c; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> ct[i][j];


  if (!valid(ct, from) || !valid(ct, to)) {
    printf("-1\n");
    return;
  }

  queue<pair<string, int> > q;
  q.push(make_pair(from, 0));
  set<string> seen;

  while (!q.empty()) {
    string cur = q.front().first;
    int dist   = q.front().second;
    q.pop();

    if (cur == to) {
      printf("%d\n", dist);
      return;
    }
    if (seen.count(cur))
      continue;

    seen.insert(cur);
    for (int i = 0; i < 3; ++i) {
      string next = cur;
      next[i] = add(cur[i]);
      if (valid(ct, next))
        q.push(make_pair(next, dist + 1));
      next[i] = sub(cur[i]);
      if (valid(ct, next))
        q.push(make_pair(next, dist + 1));
    }
  }

  printf("-1\n");

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
