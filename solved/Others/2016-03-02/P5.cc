#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  while (scanf("%d:%d", &a, &b) == 2) {
    a = a * 60 + b + 60;
    cout << "Atraso maximo: " << max(a - (8 * 60), 0) << endl;
  }
  return 0;
}
