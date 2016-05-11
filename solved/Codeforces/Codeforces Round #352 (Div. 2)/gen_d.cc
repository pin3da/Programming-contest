#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

// const int MN = 1000 * 1000 * 1000 + 1;
const int MN = 10;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int n = MN;
  int k = rand() % MN;
  cout << n << ' ' << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << rand() % MN << ' ';
  }
  return 0;
}
