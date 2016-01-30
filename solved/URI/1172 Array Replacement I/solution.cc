#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a;
  for (int i = 0; i < 10; ++i) {
    cin >> a;
    printf("X[%d] = %d\n", i, max(1, a));
  }
  return 0;
}
