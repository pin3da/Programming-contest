// http://codeforces.com/contest/379/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 500005

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }


int used[MN*2];
int ans[MN];

struct P{
  int i,p;
  P(){}
  P(int a, int b) : i(a), p(b){}
  bool operator < (const P &o) const {
    if(p == o.p) return i < o.i;
    return p < o.p;
  }
};

P num[MN];

int main(){ ___
  int n;
  while(cin>>n){

    for(int i = 0; i <n; ++i){
      cin>>num[i].p;
      num[i].i = i;
    }

    sort(num, num +n);
    memset(used, 0, sizeof used);
    map<int,int> cod;

    int last = -1;
    for(int i = 0; i< n; ++i){
      if(last < num[i].p){
        last = ans[num[i].i] = num[i].p;
      }else{
        last++;
        ans[num[i].i] = last;
      }
    }

    for(int i = 0; i< n; ++i){
      if(i) cout<<" ";
      cout<<ans[i];
    }
    cout<<endl;



  }
  return 0;

}