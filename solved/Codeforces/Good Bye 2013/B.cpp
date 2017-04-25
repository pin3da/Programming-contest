// http://codeforces.com/contest/379/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 505

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }

int nums[MN];


int main(){ ___
  int n;
  while(cin>>n){
    for(int i = 0; i< n; ++i)
      cin>>nums[i];

    for(int i = 0; i< nums[0]; ++i){
      cout<<"RLP";
    }
    cout<<"R";
    for(int i = 1; i < n; ++i){
      for(int j = 0; j < nums[i] ; ++j)
          cout<<"LRP";
      if(i + 1 < n)cout<<"R";
    }

  std::cout<< std::endl;

  }
  return 0;

}