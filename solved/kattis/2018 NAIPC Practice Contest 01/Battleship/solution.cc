#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

struct board {
  vector<vector<char>> b;
  int ships;
  board(int w, int h) : b(h, vector<char>(w)) {
    ships = 0;
  }
  int attack(int x, int y) {
    if (b[x][y] == '#') {
      b[x][y] = '_';
      ships--;
      return 1;
    }
    return 0;
  }
};


void solve() {
  int w, h, n;
  cin >> w >> h >> n;
  board p1(w, h), p2(w, h);
  for (auto &it : p1.b) for (auto &i : it) cin >> i;
  for (auto &it : p2.b) for (auto &i : it) cin >> i;

  for (auto &it : p1.b) for (auto &i : it) if (i == '#') p1.ships++;
  for (auto &it : p2.b) for (auto &i : it) if (i == '#') p2.ships++;

  vector<board> players({p1, p2});

  vector<pair<int, int>> moves;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    moves.emplace_back(h - 1 - y, x);
  }

  int cur = 1;
  for (int i = 0; i < n; i++) {
    int point = players[cur].attack(moves[i].first, moves[i].second);
    if (point) {
      if (players[cur].ships == 0) {
        if (cur == 1) {
          cur ^= 1; // make sure they have the same number of turns
        } else {
          break;
        }
      }

    } else {
      if (cur == 0 && players[1].ships == 0)
        break;
      cur ^= 1;
    }
  }

  int draw = (players[0].ships == 0) && (players[1].ships == 0);
  draw |= (players[0].ships != 0) && (players[1].ships != 0);

  if (draw) {
    cout << "draw" << endl;
  } else {
    if (players[1].ships == 0)
      cout << "player one wins" << endl;
    else
      cout << "player two wins" << endl;
  }

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
