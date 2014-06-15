using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 300030;


pair<int,int> one[MN], two[MN];

long long n,w;
long long image[MN];

int fun(int x) {
  vector<int> visited(n, 0);
  long long ans = 0;
  /*for (int i = 0; i < x; ++i) {
    visited[two[i].second]  = true;
    ans += two[i].first;
  }
  long long count = 2LL*x;
  int j = 0;
  while (j < n and count < w) {
    if (visited[j]) continue;
    ans += one[j];
    count++;
  }
}

int main() { ___

  cin>>n>>w;
  for (int i = 0; i < n; ++i) {
    cin>>one[i].first>>two[i].first;
    one[i].second = two[i].second = i;
  }

  sort(one, one + n);
  sort(two, two + n);

  int lo = 0; hi = n;

  while (lo < hi) {
    if (lo + 1 == hi) {
      if (!fun(lo))
        lo = hi;
    } else {
      int mid = (lo + hi)>>1;
      if (fun(mid))
        hi = mid;
      else
        lo = mid + 1;
    }
  }

  cout<<cost(lo);
  return 0;
}


