#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MX = 505;
short white[MX][MX], black[MX][MX];
int n;

void genSum() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      white[i][j] += white[i - 1][j] + white[i][j - 1] - white[i - 1][j - 1];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      black[i][j] += black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1];
    }
  }
}

int getsum(int i, int j, int x, int y, int col) {
  if (col == 0) {
    return black[x][y] - black[x][j - 1] - black[i - 1][y] + black[i - 1][j - 1];
  }
  return white[x][y] - white[x][j - 1] - white[i - 1][y] + white[i - 1][j - 1];
}

struct points {
  short x,y,l;
  points(){}
  points(short _x, short _y, short _l){
    x = _x;
    y = _y;
    l = _l;
  }

  bool operator <(const points &b) const {
    if (x == b.x) {
      if (y == b.y) return l < b.l;
      return y < b.y;
    }
    return x < b.x;
  }
};

int mx[] = {-1, -1, 1, 1};
int my[] = {-1, 1, 1, -1};

bool f(int m, int x, int y, int ix, int c) {
  int tx = mx[ix] * m;
  int ty = my[ix] * m;
  int newx = min(x, x + tx);
  int newy = min(y, y + ty);

  if(newx < 1 || newy < 1 || newx + m > n || newy + m > n) return 0;
  //cout << x << " " << y << " " << newx << " " << newy << " " << m << endl;

  int r = getsum(newx, newy, newx + m, newy + m, c ^ 1);
  return r == 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m, b, w, x, y;
  while(cin >> n >> m) {
    memset(white, 0, sizeof white);
    memset(black, 0, sizeof black);
    vector<pair<int,int> > cwhite(m), cblack(m);
    for(int i = 0; i < m; i++) {
      cin >> x >> y;
      cblack[i] = make_pair(x, y);
      black[x][y] = 1;
    }
    for(int i = 0; i < m; i++) {
      cin >> x >> y;
      cwhite[i] = make_pair(x, y);
      white[x][y] = 1;
    }
    genSum();
    int ansb = m, answ = m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int l = 1; l <= n; ++l) {
          int x = i + l, y = j + l;
          if (x > n || y > n) break;
          int nb = getsum(i, j, x, y, 0),
              nw = getsum(i, j, x, y, 1);
          if (nb) {
            if (nw == 0) ansb++;
            else break;
          }
        }
        for (int l = 1; l <= n; ++l) {
          int x = i + l, y = j + l;
          if (x > n || y > n) break;
          int nb = getsum(i, j, x, y, 0),
              nw = getsum(i, j, x, y, 1);
          if (nw) {
            if (nb == 0) answ++;
            else break;
          }
        }
      }
    }

    cout << ansb << " " << answ << endl;
  }
}
