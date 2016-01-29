#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double x;
  cin >> x;
  if (x <= 2000.0)
    printf("Isento\n");
  else if (x <= 3000.0)
    printf("R$ %.2llf\n", (x - 2000.0) * 0.08);
  else if (x <= 4500.0)
    printf("R$ %.2llf\n", (x - 3000.0) * 0.18 + 1000.0 * 0.08);
  else
    printf("R$ %.2llf\n", (x - 4500.0) * 0.28 + 1000.0 * 0.08 + 1500.0 * 0.18);
  return 0;
}
