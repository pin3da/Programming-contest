#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;
vector<int> nxt(MN);

void init() {
  for (int n = 1; n < MN; n++) {
    int n2 = n * n;
    nxt[n] = (n2 / 100) % 10000;
  }
}

pair<int,int> th(int x0) {
  int t = nxt[x0], h = nxt[nxt[x0]];
  while (t != h) {
    t = nxt[t];
    h = nxt[nxt[h]];
  }

  int mu = 0; h = x0;
  while (t != h) {
    t = nxt[t];
    h = nxt[h];
    mu++;
  }

  int lambda = 1; h = nxt[t];
  while (t != h) {
    h = nxt[h];
    lambda++;
  }

  return make_pair(mu, lambda);
}

int main() {
  init();
  int a0;
  while (cin >> a0 and a0) {
    pair<int,int> ans = th(a0);
    cout << ans.first + ans.second << endl;
  }
  return 0;
}
