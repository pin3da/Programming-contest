using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 500005;
const int ML = 20; // ceil(log(MN) / log(2.0))

int nums[MN];
int M[MN][ML];

int n;
long long sum[MN];
long long sumsqr[MN];

long long fun(int b, int e) {
  if (e < b) return 0;

  int k = log2(e - b + 1);
  int a = M[b][k], a2 = M[e + 1 - (1<<k)][k];
  int i = nums[a] <= nums[a2] ? a : a2;

  long long before = (i - b + 1);
  long long after  = (e - i + 1);

  long long ans = ((long long) nums[i]) * (sumsqr[before] +  (2LL * after * sum[before]) + (before * after * after) - before * after - sum[before]) / 2LL;

  return ans + fun(b, i - 1) + fun (i + 1, e);
}

int main() {

  sum[0] = sumsqr[0] = 0;
  for (int i = 1; i < MN; ++i) {
    sum[i] = sum[i - 1] + i;
    sumsqr[i] = sumsqr[i - 1] + (i*i);
  }

  int tc;scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", nums + i);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        long long tmp = 0;
        int mmin = nums[i];

        for (int k = i; k <= j; ++k) {
          mmin = min(mmin, nums[k]);
        }

        for (int k = i; k <= j; ++k) {
          tmp += nums[k] - mmin;
        }
        ans += tmp;
      }
    }

    printf("Case %d: %lld\n", t, ans);
  }
  return 0;
}
