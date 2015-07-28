using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int N = 1e5 + 10;  // limit for array size
int n = N;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = __gcd(t[i<<1], t[i<<1|1]);
}

// Single modification, range query.
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = __gcd(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = __gcd(res, t[l++]);
    if (r&1) res = __gcd(t[--r], res);
  }
  return res;
}



int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  cin >> m;
  char op;
  int idx = 0,num;
  map<int,vector<int> > indices;

  memset(t, 0, sizeof t);
  build();
  for (int i = 0; i < m; ++i) {
    cin >> op >> num;
    if (op == '+') {
      modify(idx, num);
      indices[num].push_back(idx);
      idx++;
    } else {
      int idxBorrar = indices[num].back();
      indices[num].pop_back();
      modify(idxBorrar, 0);
    }
    cout << max(query(0, N - 1), 1) << endl;
  }
  return 0;
}
