#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

int base = 10;
map<int, int> conv;
map<int, int> inv;

int getnumber(vector<int> &b) {
  int ans = 0;
  for (int i = 0; i < b.size(); ++i) {
    ans *= base;
    ans += conv[b[i]];
  }
  return ans;
}

vector<int> getboard(int b) {
  vector<int> ans(8);
  for (int i = 0; i < 8; ++i) {
    ans[i] = inv[b % base];
    b /= base;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

const int MD = 40320 + 100;
const long long inf = 1LL << 60;
map<long long, long long> dist;

int t[8][3] = {
  {0, 1, 4},
  {-1, 1, 4},
  {-1, 1, 4},
  {-1, 0, 4},
  {0, 1, -4},
  {-1, 1, -4},
  {-1, 1, -4},
  {-1, 0, -4}
};

struct st {
  int node;
  long long cost;
  st(int a, long long b) : node(a), cost(b) {}
  bool operator < (const st &o) const {
    return cost > o.cost;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> board(8), tar(8);
  while (cin >> board[0]) {
    set<int> name;
    for (int i = 1; i < 8; ++i) cin >> board[i];
    for (int i = 0; i < 8; ++i) {
      cin >> tar[i];
      name.insert(tar[i]);
    }

    conv.clear();
    inv.clear();
    int id = 0;
    for (set<int>::iterator it = name.begin(); it != name.end(); ++it) {
      conv[*it] = id;
      inv[id] = *it;
      id++;
    }

    for (int i = 0; i < MD; ++i) dist[i] = inf;

    priority_queue<st> q;

    int target = getnumber(tar);
    int start = getnumber(board);
    dist[start] = 0;
    q.push(st(start, 0));

    while (!q.empty()) {
      int state = q.top().node; q.pop();
      if (state == target) {
        break;
      }
      vector<int> cur = getboard(state);
      for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
          vector<int> nx = cur;
          int x = i + t[i][j];
          swap(nx[i], nx[x]);
          int extra = nx[i] + nx[x];
          int to = getnumber(nx);
          if ((dist.count(to) == 0) || (dist[state] + extra < dist[to])) {
            dist[to] = dist[state] + extra;
            q.push(st(to, dist[to]));
          }
        }
      }
    }
    cout << dist[target] << endl;
  }
  return 0;
}
