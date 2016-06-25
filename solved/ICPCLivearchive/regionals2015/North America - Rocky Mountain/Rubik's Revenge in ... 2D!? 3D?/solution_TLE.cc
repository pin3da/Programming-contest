#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef string state;

typedef unordered_map<state, int> umap;

void bfs(state s, umap &ans, int depth) {
  ans[s] = 0;

  deque<state> q;
  q.push_back(s);
  while (!q.empty()) {
    state cur = q.front(); q.pop_front();
    int cur_ans = ans[cur];
    if (cur_ans == depth) break;
    for (int i = 0; i < 4; ++i) {
      state next = cur;
      for (int j = 0; j < 4; ++j)
        next[i * 4 + (j + 1) % 4] = cur[i * 4 + j];
      if (ans.count(next) == 0) {
        ans[next] = cur_ans + 1;
        q.push_back(next);
      }

      next = cur;
      for (int j = 0; j < 4; ++j)
        next[i * 4 + (j - 1 + 4) % 4] = cur[i * 4 + j];
      if (ans.count(next) == 0) {
        ans[next] = cur_ans + 1;
        q.push_back(next);
      }

      next = cur;
      for (int j = 0; j < 4; ++j)
        next[((j + 1) % 4) * 4 + i] = cur[j* 4 + i];
      if (ans.count(next) == 0) {
        ans[next] = cur_ans + 1;
        q.push_back(next);
      }

      next = cur;
      for (int j = 0; j < 4; ++j)
        next[((j - 1 + 4) % 4) * 4 + i] = cur[j * 4 + i];
      if (ans.count(next) == 0) {
        ans[next] = cur_ans + 1;
        q.push_back(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s = "RRRRGGGGBBBBYYYY";
  string line;
  umap start;
  start.reserve(4147187 + 10);
  bfs(s, start, 6);
  while (cin >> line) {
    string c = line;
    for (int i = 0; i < 3; ++i) {
      cin >> line;
      c += line;
    }
    umap end;
    end.reserve(4147187 + 10);
    bfs(c, end, 5);
    int best = 12;
    for (auto &i: start) {
      if (end.count(i.first)) {
        best = min(best, i.second + end[i.first]);
      }
    }
    cout << best << endl;
  }

  return 0;
}
