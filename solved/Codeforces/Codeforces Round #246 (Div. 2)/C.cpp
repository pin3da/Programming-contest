// http://codeforces.com/contest/432/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

using namespace std;

const int MN = 100000 + 10;

int p[MN];
vector<int> a[MN];
int sieve[MN];
int pc;

void fill_s() {
  sieve[0] = sieve[1] = true;
  pc = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      p[pc++] = i;
      for (int j = i + i; j < MN; j += i) {
        sieve[j] = true;
      }
    }
  }

  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      a[i].push_back(i);
    } else {
      for (int j = 0; j < pc; ++j) {
        int k = i - p[j];
        if (!sieve[k]) {
          a[i].push_back(max(p[j], k));
          a[i].push_back(min(p[j], k));
          break;
        }
      }
    }
  }
}

void op(vector<int> &arr, vector<int> &inv, vector<pair<int, int>> &ans, int i, int j) {
  if (i == j) return;
  assert(!sieve[j - i + 1]);
  int x = arr[i];
  int y = arr[j];

  inv[x] = j;
  inv[y] = i;
  arr[i] = y;
  arr[j] = x;

  ans.emplace_back(i, j);
}

int main() {
  fill_s();
  int n;
  while (cin >> n) {
    vector<int> arr(n), inv(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      arr[i]--;
      inv[arr[i]] = i;
    }

    vector<pair<int, int>> ans;
    ans.reserve(n * 3);
    for (int i = 0; i < n; ++i) {
      if (arr[i] == i) continue;
      int dist = inv[i] - i + 1;
      if (sieve[dist]) {
        int to = inv[i];
        if (dist & 1) {
          op(arr, inv, ans, to - 1, to);
          to--;
          dist--;
        }
        vector<int> &xx = a[dist];
        op(arr, inv, ans, to - xx[0] + 1, to);
        op(arr, inv, ans, i + 1, to - xx[0] + 1);
        op(arr, inv, ans, i, i + 1);
      } else {
        assert(!sieve[dist]);
        op(arr, inv, ans, i, inv[i]);
      }
    }

    cout << ans.size() << endl;
    for (auto &i : ans)
      cout << i.first + 1 << " " << i.second + 1 << endl;
  }
  return 0;
}
