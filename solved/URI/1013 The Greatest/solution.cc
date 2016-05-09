#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int maior(int a, int b) {
  return (a + b + abs(b - a)) / 2;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c;
  while (cin >> a >> b >> c)
    cout <<  maior(maior(a, b), c) << " eh o maior" << endl;

  return 0;
}
