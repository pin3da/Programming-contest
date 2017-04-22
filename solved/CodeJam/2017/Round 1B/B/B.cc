// small: correct
// large: wrong

#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int RED = 0, YEL = 1, BLU = 2;

struct col {
  char t;
  int frec;
  bool operator < (const col &o) const {
    if (frec == o.frec) return t > o.t;
    return frec > o.frec;
  }
};

int put(string &ans, int pos, col cur) {
  while (cur.frec--) {
    while (ans[pos] != ' ')
      pos = (pos + 1) % ans.size();
    ans[pos] = cur.t;
    pos = (pos + 2) % ans.size();
  }
  return pos;
}

void solve_small(int r, int b, int y, int dr, int dy, int db) {
  vector<col> all = {{'R', r}, {'B', b}, {'Y', y}};
  sort(all.begin(), all.end());
  if (all[0].frec > all[1].frec + all[2].frec) {
    puts("IMPOSSIBLE");
    return;
  }
  string ans(r + b + y, ' ');
  int pos = 0;
  for (int i = 0; i < 3; ++i)
    pos = put(ans, pos, all[i]);
  for (auto c : ans) {
    if (c == 'R') {
      if (dr) {
        printf("RG");
        dr--;
      }
      printf("R");
    }
    if (c == 'Y') {
      if (dy) {
        printf("YV");
        dy--;
      }
      printf("Y");
    }
    if (c == 'B') {
      if (db) {
        printf("BO");
        db--;
      }
      printf("B");
    }
  }
  puts("");
}

void fun(int len, char a, char b) {
  for (int i = 0; i < len; ++i) {
    printf("%c%c", a, b);
    ++i;
  }
  puts("");
}

void solve() {
  int n;
  cin >> n;
  int R, O, Y, G, B, V;
  cin >> R >> O >> Y >> G >> B >> V;
  int x = G, y = V, z = O;
  int ok = true;
  if ((Y + V) == n && (Y == V)) {
    fun(n, 'Y', 'V');
    return;
  }
  if ((R + G) == n && (R == G)) {
    fun(n, 'R', 'G');
    return;
  }
  if ((O + B) == n && (O == B)) {
    fun(n, 'O', 'B');
    return;
  }
  while (G) {
    if (R >= 2) R--;
    else ok = false;
    G--;
  }
  while (V) {
    if (Y >= 2) Y--;
    else ok = false;
    V--;
  }
  while (O) {
    if (B >= 2) B--;
    else ok = false;
    O--;
  }
  if (ok) {
    solve_small(R, B, Y, x, y, z);
  } else {
    puts("IMPOSSIBLE");
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
