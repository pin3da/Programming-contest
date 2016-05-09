#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= 10000; ++i)
      if ((i % n) == 2)
        cout << i << endl;
  }
  return 0;
}
