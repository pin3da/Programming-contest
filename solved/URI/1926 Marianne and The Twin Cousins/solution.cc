#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1000001;

struct ht {
  int _s[(MN + 10) >> 5];
  int len;
  ht () {
    len = 0;
    memset(_s, 0, sizeof _s);
  }
  void set(int id) {
    len++;
    _s[id >> 5] |= (1LL << (id & 31));
  }
  bool is_set(int id) {
    return _s[id >> 5] & (1LL << (id & 31));
  }
};

ht sieve;
int twins[MN];
const int MP = 78498 + 10;
int p[MP];
unordered_map<int, int> idx;

void fill_p() {
  sieve.set(0);
  sieve.set(1);
  int S = 1000;
  for (int i = 2; i <= S; ++i)
    if (!sieve.is_set(i))
      for (int j = i * i; j < MN; j += i)
        sieve.set(j);

  int j = 0;
  for (int i = 0; i < MN; ++i)
    if (!sieve.is_set(i)) {
      idx[i] = j;
      p[j] = i;
      j++;
    }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fill_p();

  for (int  i = 0; i < MN; ++i) {
    if (!sieve.is_set(i)) {
      if (i > 1)
        if (!sieve.is_set(i - 2))
          twins[i] = 1;
      if (i + 2 < MN)
        if (!sieve.is_set(i + 2))
          twins[i] = 1;
    }
    if (i)
      twins[i] += twins[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    x--;
    cout << twins[y] - twins[x] << endl;
  }
  return 0;
}

