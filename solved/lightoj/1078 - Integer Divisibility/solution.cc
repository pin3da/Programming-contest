using namespace std;
#include<cstdio>

int solve(int n,int m) {
  int ans = 1;
  int tmp = m % n;
  while (tmp) {
    tmp= tmp * 10 + m;
    if(tmp >= n)
      tmp %= n;
    ans++;
  }
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  int n, m;
  for (int i = 0; i < tc; ++i) {
    scanf("%d%d", &n, &m);
    printf("Case %d: %d\n", i+1, solve(n, m));
  }
  return 0;
}
