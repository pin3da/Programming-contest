#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int idx[2][8] = {
  {13, 14, 5, 6, 17, 18, 21, 22},
  {15, 16, 7, 8, 19, 20, 23, 24},
};

int idy[2][8] = {
  {2, 4, 6, 8, 10, 12, 23, 21},
  {1, 3, 5, 7, 9, 11, 24, 22},
};

int idz[2][8] = {
  {4, 3, 14, 16, 9, 10, 19, 17},
  {2, 1, 13, 15, 11, 12, 20, 18},
};


bool valid(vector<int> &cube) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      int s = i * 4;
      if (cube[s] != cube[s + j]) return false;
    }
  }
  return true;
}

void debug_cube(vector<int> &cube) {
  for (auto i: cube)
    cout << i << ' ';
  cout << endl;
}

int check(vector<int> &cube, int id[2][8]) {
  for (int i = 0; i < 2; i++) {
    vector<int> next = cube;
    for (int j = 0; j < 8; j++)
      next[id[i][(j + 2) % 8]] = cube[id[i][j]];

//     debug_cube(next);
    if (valid(next)) return 1;

    for (int j = 0; j < 8; j++)
      next[id[i][(j + 6) % 8]] = cube[id[i][j]];

  //  debug_cube(next);
    if (valid(next)) return 1;
  }
  return 0;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<int> cube(24);
  for (auto &i : cube) cin >> i;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 8; j++) {
      idx[i][j]--;
      idy[i][j]--;
      idz[i][j]--;
    }
  }

  if (check(cube, idx)) {
    cout << "YES" << endl;
    return 0;
  }
  if (check(cube, idy)) {
    cout << "YES" << endl;
    return 0;
  }
  if (check(cube, idz)) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
  return 0;
}
