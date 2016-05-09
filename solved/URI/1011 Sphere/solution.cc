#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

double pi = 3.14159;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double r;
  while (cin >> r)
    cout << "VOLUME = " << fixed << setprecision(3) << (4.0 / 3.0) * r * r * r * pi << endl;
  return 0;
}
