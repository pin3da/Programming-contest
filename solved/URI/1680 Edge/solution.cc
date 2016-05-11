#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {10, 0, -10, 0};
int dy[] = {0, -10, 0, 10};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    int x = 300, y = 420;
    cout << x << " " << y << " moveto" << endl;
    x += 10;
    cout << x << " " << y << " lineto" << endl;

    int dir = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == 'A')
        dir = (dir + 1) % 4;
      else
        dir = (dir + 3) % 4;

      x += dx[dir];
      y += dy[dir];

      cout << x << " " << y << " lineto" << endl;
    }
    cout << "stroke" << endl;
    cout << "showpage" << endl;
  }

  return 0;
}
