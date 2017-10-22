#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

int find_set(vector<int> &p, int x) {
  return p[x] == x ? x : p[x] = find_set(p, p[x]);
}

void js(vector<int> &p, int x, int y) {
  int px = find_set(p, x);
  int py = find_set(p, y);
  p[px] = py;
}

void solve(int n) {
  string line;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  while (getline(cin, line) && line.size()) {
    js(p, line[0] - 'A', line[1] - 'A');
  }

  set<int> roots;
  for (int i = 0; i < n; i++) {
    roots.insert(find_set(p, i));
  }
  cout << roots.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  while (getline(cin, line)) {
    if (line.size() == 1) {
      solve(1 + line[0] - 'A');
    }
  }

  return 0;
}
