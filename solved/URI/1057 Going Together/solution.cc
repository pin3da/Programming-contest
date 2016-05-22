using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 11;
char g[MN][MN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


typedef pair<int, int> entry;
typedef pair<vector<entry>, int> state;

struct hash_table{
  int  _seen[1976791 >> 5];
  hash_table() {
    memset(_seen, 0, sizeof _seen);
  }

  int index(const vector<entry> &c) {
    int i = c[0].first * 10 + c[0].second;
    i <<= 7;
    i += c[1].first * 10 + c[1].second;
    i <<= 7;
    i += c[2].first * 10 + c[2].second;
    return i;
  }

  bool seen(const vector<entry> &c) {
    int i = index(c);
    return _seen[i >> 5] & (1LL << (i & 31));
  }

  void mark(const vector<entry> &c) {
    int i = index(c);
    _seen[i >> 5] |= (1LL << (i & 31));
  }
};

bool finished(const vector<entry> &cur) {
  for (int i = 0; i < cur.size(); ++i) {
    int x = cur[i].first;
    int y = cur[i].second;
    if (g[x][y] != 'X')
      return false;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<entry> p(3);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'A') {
        p[0] =  make_pair(i, j);
        g[i][j] = '.';
      }
      if (g[i][j] == 'B') {
        p[1] = make_pair(i, j);
        g[i][j] = '.';
      }
      if (g[i][j] == 'C') {
        p[2] = make_pair(i, j);
        g[i][j] = '.';
      }
    }
  }

  sort(p.begin(), p.end());

  deque<state> q;
  q.push_back(make_pair(p, 0));
  hash_table visited;

  int ans = 1 << 30;

  while (!q.empty()) {
    state cur = q.front();
    q.pop_front();
    if (visited.seen(cur.first))
      continue;

    visited.mark(cur.first);

    if (finished(cur.first)) {
      ans = cur.second;
      break;
    }

    vector<entry> &pos = cur.first;
    for (int i = 0; i < 4; ++i) {
      vector<entry> npos;
      for (int j = 0; j < pos.size(); ++j) {
        int x = pos[j].first + dx[i];
        int y = pos[j].second + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < n && g[x][y] != '#') {
          npos.push_back(make_pair(x, y));
        } else {
          npos.push_back(pos[j]);
        }
      }

      vector<entry> cool(3);
      cool[0] = (npos[0] == npos[1] || npos[0] == npos[2]) ?  pos[0] : npos[0];
      cool[1] = (npos[1] == npos[0] || npos[1] == npos[2]) ?  pos[1] : npos[1];
      cool[2] = (npos[2] == npos[0] || npos[2] == npos[1]) ?  pos[2] : npos[2];

      sort(cool.begin(), cool.end());
      cool.resize(unique(cool.begin(), cool.end()) - cool.begin());
      if (cool.size() < 3)
        continue;
      if (!visited.seen(cool)) {
        q.push_back(make_pair(cool, cur.second + 1));
      }
    }
  }

  if (ans < (1 << 30))
    printf("%d\n", ans);
  else
    puts("trapped");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}

