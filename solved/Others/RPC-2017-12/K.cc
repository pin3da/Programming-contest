#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

string sa, sb;
vector<string> ans;

int mx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int my[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char keyboard[3][10] = {
  {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '*'},
  {'z', 'x', 'c', 'v', 'b', 'n', 'm', '*', '*', '*'}
};

bool is_adjacent(char ca, char cb) {
  int x, y, f = 0;
  for (x = 0; x < 3 && !f; x++)
    for (y = 0; y < 10 && !f; y++)
      if (keyboard[x][y] == ca)
        f = 1;
  x--; y--;
  for (int i = 0; i < 8; i++) {
    int nx = x + mx[i], ny = y + my[i];
    if (nx < 0 || nx >= 3 || ny < 0 || ny >= 10) continue;
    if (keyboard[nx][ny] == cb) return true;
  }
  return false;
}

void solver(int pa, int pb, string cmd) {
  if (pa == sa.size()) {
    if (pb == sb.size() - 1) ans.push_back(cmd);
    return;
  }
  // OK
  if (sa[pa] == sb[pb])
    solver(pa + 1, pb + 1, cmd + "o");
  // FORGOT
  solver(pa + 1, pb, cmd + "f");
  // WRONG
  if (is_adjacent(sa[pa], sb[pb]))
    solver(pa + 1, pb + 1, cmd + "w");
  // EXTRA
  if (pb + 1 == sb.size()) return;
  // EXTRA LEFT
  if (is_adjacent(sb[pb], sb[pb + 1]) && sa[pa] == sb[pb + 1])
    solver(pa + 1, pb + 2, cmd + "l");
  // EXTRA RIGHT
  if (is_adjacent(sb[pb], sb[pb + 1]) && sa[pa] == sb[pb])
    solver(pa + 1, pb + 2, cmd + "r");
}

int next_int() {
  string num; getline(cin, num);
  return atoi(num.c_str());
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t = next_int();
  while (t--) {
    getline(cin, sa);
    getline(cin, sb); sb.push_back('$');
    solver(0, 0, "");
    sb.pop_back();
    sort(ans.begin(), ans.end());
    cout << sa << " " << sb << ":" << endl;
    for (string s : ans)
      cout << s << endl;
    ans.clear();
    cout << endl;
  }
  return 0;
}
