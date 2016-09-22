#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl;
#define endl '\n'

const int MN = 300;
int frec[MN];
int len[MN];
int cp[MN];
int tt[MN];
int n;

int heron(int a, int b, int c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int best_tri() {
  int cur = 0;
  int t = 0;
  for (int i = MN - 1; i >= 0; --i) {
    for (int j = 0; j < cp[i]; ++j) {
      tt[t++] = i;
    }
  }

  for (int i = 0; i + 2 < t; ++i) {
    if (tt[i] < tt[i + 1] + tt[i + 2]) {
      cur = max(cur, heron(tt[i], tt[i + 1], tt[i + 2]));
    }
  }
  return cur;
}

int fun() {
  memset(frec, 0, sizeof frec);
  memset(cp, 0, sizeof cp);
  for (int i = 0; i < n; ++i)
    frec[len[i]]++;

  memcpy(cp, frec, sizeof cp);

  int best = best_tri();
  for (int i = MN - 1; i >= 0; --i) {
    if (frec[i] >= 4) {
      cp[i] -= 4;
      best = max(best, i * i + best_tri());
      cp[i] += 4;
    }
    if (frec[i] >= 2) {
      for (int j = i - 1; j >= 0; --j) {
        if (frec[j] >= 2) {
          cp[i] -= 2; cp[j] -= 2;
          best = max(best, i * j + best_tri());
          cp[i] += 2; cp[j] += 2;
        }
      }
    }
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> len[i];
    cout << fun() << endl;
  }
  return 0;
}
