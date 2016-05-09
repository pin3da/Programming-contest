#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  double h, r;
  while (cin >> n >> h >> r)
    cout << "NUMBER = " << n << endl << "SALARY = U$ "
         << fixed << setprecision(2) << h * r << endl;

  return 0;
}
