#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

class mat {
public:
  ull m[2][2];
  mat() { memset(m, 0, sizeof m); }
  mat(ull a, ull b, ull c, ull d) {
    m[0][0] = a; m[0][1] = b;
    m[1][0] = c; m[1][1] = d;
  }

  mat operator*(mat x) {
    mat ans;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
	for (int k = 0; k < 2; k++)
	  ans.m[i][j] += m[i][k] * x.m[k][j];
    return ans;
  }
};

mat pow(mat a, int b) {
  mat ans(1, 0, 0, 1);
  while (b > 0) {
    if (b & 1)
      ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

ull solve(ull a_b, ull ab, int n) {
  if (n == 0)
    return 2; // a^0 + b^0

  mat m(a_b, -ab, 1, 0);
  m = pow(m, n - 1);
  return m.m[0][0] * a_b + 2 * m.m[0][1];
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    ull a, b; int n;
    scanf("%llu %llu %d", &a, &b, &n);
    printf("Case %d: %llu\n", i + 1, solve(a, b, n));
  }
  return 0;
}
