#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct piece {
  char t, p;
  piece () : t(-1), p(-1) {}
  piece (char a, char b): t(a), p(b) {}
  int hash() {
    return (t - 'A') * 30 + p;
  }
};

typedef pair<int, int> pos;

piece board[4][4];

int qx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int qy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[] = {1, -1, 2, -2, -2, 2, -1, 1};

int bx[] = {-1, -1, 1, 1};
int by[] = {-1, 1, -1, 1};

int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};

void print_board() {
  cout << " ---- " << endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j].p == 0)
        cout << char(tolower(board[i][j].t));
      else if (board[i][j].p == 1)
        cout << (board[i][j].t);
      else
        cout << 'x';
    }
    cout << endl;
  }
}

bool valid(int nx, int ny, int p) {
  return nx >= 0 && nx < 4 && ny >= 0 &&
    ny < 4 && board[nx][ny].p != p;
}

bool empty(int nx, int ny) {
  return nx >= 0 && nx < 4 && ny >= 0 &&
    ny < 4 && board[nx][ny].p == -1;
}

bool kill(int nx, int ny, int p) {
  return nx >= 0 && nx < 4 && ny >= 0 && ny < 4 &&
    board[nx][ny].p == (p ^ 1) && board[nx][ny].t == 'Q';
}

bool win(int p, int dep);

vector<pos> gen_moves(int i, int j, int p) {
  vector<pos> ans;
  if (board[i][j].t == 'Q') {
    for (int dir = 0; dir < 8; ++dir) {
      for (int len = 1; len < 4; ++len) {
        int nx = i + qx[dir] * len,
            ny = j + qy[dir] * len;
        if (valid(nx, ny, p))
          ans.push_back(make_pair(nx, ny));
        if (!empty(nx, ny)) break;
      }
    }
  } else if (board[i][j].t == 'N') {
    for (int dir = 0; dir < 8; ++dir) {
      int nx = i + kx[dir],
          ny = j + ky[dir];
      if (valid(nx, ny, p))
        ans.push_back(make_pair(nx, ny));
    }
  } else if (board[i][j].t == 'B') {
    for (int dir = 0; dir < 4; ++dir) {
      for (int len = 1; len < 4; ++len) {
        int nx = i + bx[dir] * len,
            ny = j + by[dir] * len;
        if (valid(nx, ny, p))
          ans.push_back(make_pair(nx, ny));
        if (!empty(nx, ny)) break;
      }
    }
  } else if (board[i][j].t == 'R') {
    for (int dir = 0; dir < 4; ++dir) {
      for (int len = 1; len < 4; ++len) {
        int nx = i + rx[dir] * len,
            ny = j + ry[dir] * len;
        if (valid(nx, ny, p))
          ans.push_back(make_pair(nx, ny));
        if (!empty(nx, ny)) break;
      }
    }
  }
  return ans;
}


bool can_win(int p) {
  int seen = 0;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (board[i][j].t == 'Q' && board[i][j].p == (p ^ 1))
        seen = true;

  assert(seen);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j].p == p) {
        vector<pos> nxt = gen_moves(i, j, p);
        for (size_t k = 0; k < nxt.size(); ++k) {
          int nx = nxt[k].first,
              ny = nxt[k].second;
          if (kill(nx, ny, p))
            return true;
        }
      }
    }
  }
  return false;
}

bool t1(int p, int dep) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j].p == p) {
        vector<pos> nxt = gen_moves(i, j, p);
        for (size_t k = 0; k < nxt.size(); ++k) {
          int nx = nxt[k].first,
              ny = nxt[k].second;
          piece tmp[4][4];
          memcpy(tmp, board, sizeof board);
          assert(board[nx][ny].p != board[i][j].p);
          if (board[nx][ny].t == 'Q') return p ^ 1;
          board[nx][ny] = board[i][j];
          board[i][j] = piece();
          if (win(p ^ 1, dep + 1) != p) return p ^ 1;
          memcpy(board, tmp, sizeof board);
        }
      }
    }
  }
  return p;
}

int m;
bool win(int p, int dep) {
  if (dep >= m) return false;
  if (p == 0) {
    if (can_win(p)) return true;
  }
  else {
    if (can_win(p)) return false;
  }
  return t1(p, dep);
}

void solve() {
  int w, b;
  cin >> w >> b >> m;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      board[i][j] = piece();

  for (int i = 0; i < w; ++i) {
    char t, x, y;
    cin >> t >> x >> y;
    board[x - 'A'][y - '1'] = piece(t, 0);
  }
  for (int i = 0; i < b; ++i) {
    char t, x, y;
    cin >> t >> x >> y;
    board[x - 'A'][y - '1'] = piece(t, 1);
  }
  // print_board();
  if (win(0, 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

