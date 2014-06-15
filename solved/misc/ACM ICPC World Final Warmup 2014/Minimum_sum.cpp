using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 500005;
const int ML = 20; // ceil(log(MN) / log(2.0))

long long nums[MN];
long long M[MN][ML];

int n;
long long sum[MN];
long long sumsqr[MN];

long long fun(int b, int e) {
  if (e < b) return 0;

  int k = log2(e - b + 1);
  long long a = M[b][k], a2 = M[e + 1 - (1<<k)][k];
  int idx = nums[a] <= nums[a2] ? a : a2;

  long long before = (idx - b + 1);
  long long after  = (e - idx + 1);

  long long ans = 0;

  long long sumj = (after * (after + 2LL * before - 1)) / 2LL;
  long long x = nums[idx] * sumj;
  long long y = after * nums[idx];
  long long z = after * nums[idx];

  ans = (before * x) - ((y * before * (before + 1LL)) / 2LL) + (before * z);

  long long var =  ans + fun(b, idx - 1) + fun (idx + 1, e);
  return var;
}

int main() {

  int tc;scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", nums + i);

    long long ans = 0;

    for (int i = 0; i < n; ++i) M[i][0] = i;
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i) {
        long long a = M[i][j - 1], b = M[i + q][j - 1];
        M[i][j] = nums[a] <= nums[b] ? a : b;
      }

    for (int i = 0; i < n; ++i)
      ans += (i + 1) * (nums[i] * (n - i));

    ans -= fun(0, n - 1);

    printf("Case %d: %lld\n", t, ans);
  }
  return 0;
}
