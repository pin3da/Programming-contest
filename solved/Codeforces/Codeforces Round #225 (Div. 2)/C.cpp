// http://codeforces.com/contest/384/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    if(from == 0) return query(to);
    return query(to) - query(from-1);
  }

};

int main(){ ___

  int n;cin>>n;
  set<int> pr,pl;
  FenwickTree tr(n+10);
  FenwickTree tl(n+10);
  int t;
  For(i,n){
    cin>>t;
    if(t){
      pl.insert(i);
      tl.add(i,1);
    }else{
      pr.insert(i);
      tr.add(i,1);
    }
  }

  int turn = 0;

  long long ans = 0;
  int kill = 0;
  while(kill < n){

    if(pl.size() and pr.size()){
      if((*pl.begin()) < (n - 1 - (*pr.rbegin()))){
        turn = 0 ;
      }else{
        turn = 1;
      }
    }else{
      if(pl.size()){
        turn = 0;
      }else if(pr.size()){
        turn = 1;
      }else{
        break;
      }
    }

    if (turn == 0) {
      int pos = *pl.begin();
      pl.erase(pl.begin());
      ans += tr.query(pos + 1, n+1);
      tl.add(pos,-1);
      kill++;
    }else{
      int pos = *pr.rbegin();
      pr.erase(pr.find(pos));
      ans += tl.query(0, pos-1);
      tr.add(pos,-1);
      kill++;
    }
  }
  cout<<ans<<endl;

  return 0;

}