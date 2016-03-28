#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << "Ho";
    }
    cout << "!" << endl;
  }
  return 0;
}
