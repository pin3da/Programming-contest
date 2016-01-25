#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x, y;
  while (cin >> x >> y && (x != y)) {
    cout << (x < y ? "Crescente" : "Decrescente") << endl;
  }

  return 0;
}
