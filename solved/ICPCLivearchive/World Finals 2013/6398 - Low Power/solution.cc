using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 1000010

int p[MN];
int n,k,s;

int test(int d){
  int i = 0;
  int top = 0;
  int m = n;

  while(i < s - 1 and m > 0){
    if(p[i + 1] - p[i] <= d){
      m--;
      top += (2*k - 2);
      ++i;
    }else{
      if(top)
        top--;
      else
        return 0;
    }
    ++i;
  }

  return m == 0;

}

int main(){ ___

  while(cin>>n>>k){
    s = 2*n*k;
    for(int i = 0; i< s; ++i)
      cin>>p[i];

    sort(p, p+s);

    int lo = 0;
    int hi = 1e9 + 1;
    while(lo < hi){
      int mid = (lo + hi)>>1;
      if(test(mid)) hi = mid;
      else lo = mid + 1;
    }
    cout<<lo<<endl;
  }
  return 0;
}
