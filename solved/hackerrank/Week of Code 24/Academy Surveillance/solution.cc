// WA
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1001;
const int MID = 36;
long long dp[MN][MN][MID];
int id[1 << 10];
vector<int> ver[MID];
vector<int> hor[MID];
vector<int> diag[MID];

const long long mod = 1e9 + 7;

typedef vector<vector<int> > board;

vector<board> gen_all() {
  board base(3, vector<int>(3));

  vector<board> all;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = i; k < 3; ++k)
        for (int l = (k == i ? j + 1 : 0); l < 3; ++l) {
          board cur = base;
          cur[i][j] = 1;
          cur[k][l] = 1;
          all.push_back(cur);
        }
  return all;
}

int get_mask(board &cur) {
  int mask = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (cur[i][j]) mask |= 1 << (i * 3 + j);
  assert(__builtin_popcount(mask) == 2);
  return mask;
}


void rem_dup(vector<int> &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}

void gen_ver(vector<board> &all) {
  for (size_t k1 = 0; k1 < all.size(); ++k1) {
    for (size_t k2 = 0; k2 < all.size(); ++k2) {
      board &a = all[k1],
            &b = all[k2];

      int same = true;
      for (int i = 0; i < 2 && same; ++i) {
        for (int j = 0; j < 3 && same; ++j) {
          if(a[i + 1][j] != b[i][j]) same = false;
        }
      }
      if (same) {
        int ma = id[get_mask(a)],
        mb = id[get_mask(b)];
        ver[ma].push_back(mb);
      }
    }
  }
}


void gen_hor(vector<board> &all) {
  for (size_t k1 = 0; k1 < all.size(); ++k1) {
    for (size_t k2 = 0; k2 < all.size(); ++k2) {
      board &a = all[k1],
            &b = all[k2];

      int same = true;
      for (int j = 0; j < 2 && same; ++j) {
        for (int i = 0; i < 3 && same; ++i) {
          if(a[i][j + 1] != b[i][j]) same = false;
        }
      }
      if (same) {
        int ma = id[get_mask(a)],
        mb = id[get_mask(b)];
        hor[ma].push_back(mb);
      }
    }
  }
}

void gen_diag(vector<board> &all) {
  vector<set<int> > t(MID);
  for (size_t k1 = 0; k1 < all.size(); ++k1) {
    for (size_t k2 = 0; k2 < all.size(); ++k2) {
      board &a = all[k1],
            &b = all[k2];

      int same = true;
      for (int j = 0; j < 2 && same; ++j) {
        for (int i = 0; i < 2 && same; ++i) {
          if(a[i + 1][j + 1] != b[i][j]) same = false;
        }
      }
      if (same) {
        int ma = id[get_mask(a)],
        mb = id[get_mask(b)];
        t[ma].insert(mb);
      }
    }
  }
  vector<vector<int> > tmp(MID);
  for (int i = 0; i < MID; ++i) {
    for (size_t j = 0; j < ver[i].size(); ++j) {
      int to = ver[i][j];
      for (size_t k = 0; k < hor[to].size(); ++k) {
        int end = hor[to][k];
        tmp[i].push_back(end);
      }
    }
  }

  vector<vector<int> > tmp2(MID);
  for (int i = 0; i < MID; ++i) {
    for (size_t j = 0; j < hor[i].size(); ++j) {
      int to = hor[i][j];
      for (size_t k = 0; k < ver[to].size(); ++k) {
        int end = ver[to][k];
        tmp2[i].push_back(end);
      }
    }
  }

  for (int i = 0; i < MID; ++i) {
    for (int j = 0; j < MID; ++j) {
      int f1 = 0, f2 = 0;
      for (size_t k = 0; k < tmp[i].size(); ++k) {
        if (tmp[i][k] == j)
          f1++;
      }
      for (size_t k = 0; k < tmp2[i].size(); ++k) {
        if (tmp2[i][k] == j)
          f2++;
      }

      if (f1 && f2 && t[i].count(j)) {
        diag[i].push_back(j);
      }
    }
  }
}

long long get_ans(int i, int j) {
  long long ans = 0;

  for (int k = 0; k < MID; ++k)
    ans = (ans + dp[i][j][k]) % mod;
  return ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  vector<board> all = gen_all();
  memset(id, -1, sizeof id);
  for (size_t k = 0; k < all.size(); ++k) {
    board &cur = all[k];
    int mask = get_mask(cur);
    assert(mask < (1 << 9));
    id[mask] = k;
  }

  gen_ver(all);
  gen_hor(all);
  gen_diag(all);

  memset(dp, 0, sizeof dp);
  for (int i = 0; i < MID; ++i) {
    dp[2][2][i] = 1;
  }

  for (int i = 2; i + 1 < MN; ++i) {
    for (int m = 0; m < MID; ++m) {
      for (size_t k = 0; k < hor[m].size(); ++k) {
        int to = hor[m][k];
        dp[2][i + 1][to] = (dp[2][i + 1][to] + dp[2][i][m]) % mod;
      }
      for (size_t k = 0; k < ver[m].size(); ++k) {
        int to = ver[m][k];
        dp[i + 1][2][to] = (dp[i + 1][2][to] + dp[i][2][m]) % mod;
      }
    }
  }

  for (int i = 2; i + 1 < MN; ++i) {
    for (int j = 2; j + 1 < MN; ++j) {
      for (int m = 0; m < MID; ++m) {
        for (size_t k = 0; k < diag[m].size(); ++k) {
          int to = diag[m][k];
          dp[i + 1][j + 1][to] =
            (dp[i + 1][j + 1][to] + dp[i][j][m]) % mod;
        }
      }
    }
  }

  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    cout << get_ans(a - 1, b - 1) << endl;
  }

  return 0;
}
