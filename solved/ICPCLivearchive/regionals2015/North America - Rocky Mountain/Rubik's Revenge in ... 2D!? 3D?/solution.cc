#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef unsigned int state;

typedef unordered_map<state, int> umap;

int get_id(char &a) {
  if (a == 'R') return 0;
  if (a == 'G') return 1;
  if (a == 'B') return 2;
  return 3;
}

const string tt = "RGBY";

state convert(string &s) {
  state ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans <<= 2;
    ans += get_id(s[i]);
  }
  return ans;
}


string revert(state s) {
  string ans(16, 'R');
  int id = 15;
  while (s > 0) {
    ans[id--] = tt[(s & 3)];
    s >>= 2;
  }
  return ans;
}

void bfs(state s, umap &ans, int depth) {
  ans[s] = 0;
  deque<state> q;
  q.push_back(s);
  while (!q.empty()) {
    state cur = q.front(); q.pop_front();
    string cur_s = revert(cur);
    int cur_ans = ans[cur];
    if (cur_ans == depth) break;
    for (int i = 0; i < 4; ++i) {
      string next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(i << 2) | ((j + 1) & 3)] = cur_s[(i << 2) | j];
      state nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(i << 2) | ((j - 1 + 4) & 3)] = cur_s[(i << 2) | j];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(((j + 1) & 3) << 2) | i] = cur_s[(j << 2) | i];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(((j - 1 + 4) & 3) << 2) | i] = cur_s[(j << 2) | i];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }
    }
  }
}

int bfs2(state s, umap &ant, umap &ans, int depth) {
  ans[s] = 0;
  deque<state> q;
  q.push_back(s);
  int best = 12;
  while (!q.empty()) {
    state cur = q.front(); q.pop_front();
    string cur_s = revert(cur);
    int cur_ans = ans[cur];

    if (ant.find(cur) != ant.end())
      best = min(best, cur_ans + ant[cur]);

    if (cur_ans > best) continue;
    if (cur_ans == depth) continue;

    for (int i = 0; i < 4; ++i) {
      string next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(i << 2) | ((j + 1) & 3)] = cur_s[(i << 2) | j];
      state nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(i << 2) | ((j - 1 + 4) & 3)] = cur_s[(i << 2) | j];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(((j + 1) & 3) << 2) | i] = cur_s[(j << 2) | i];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }

      next = cur_s;
      for (int j = 0; j < 4; ++j)
        next[(((j - 1 + 4) & 3) << 2) | i] = cur_s[(j << 2) | i];
      nn = convert(next);
      if (ans.find(nn) == ans.end()) {
        ans[nn] = cur_ans + 1;
        q.push_back(nn);
      }
    }
  }
  return best;
}

const int MN = 444444;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s = "RRRRGGGGBBBBYYYY";
  string line;
  umap start(MN * 10);
  bfs(convert(s), start, 6);
  int tc = 0;
  while (cin >> line) {
    string c = line;
    for (int i = 0; i < 3; ++i) {
      cin >> line;
      c += line;
    }
    if (start.find(convert(c)) != start.end())
      cout << start[convert(c)] << endl;
    else {
      umap end(MN);
      cout << bfs2(convert(c), start, end, 5) << endl;
    }
    tc++;
  }

  return 0;
}
