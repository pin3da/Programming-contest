// http://codeforces.com/contest/187/problem/A

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

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
    return query(to) - query(from);
  }

};


int main(){
    int n;
    cin>>n;
    int primero[n];
    map<int, int> segundo;
    int tmp;
    For(i,n)cin>>primero[i];
    For(i,n){
        cin>>tmp;
        segundo[tmp]=i;
    }
    
    For(i,n)
        primero[i]=segundo[primero[i]];
    
    For(i,n-1){
        if(primero[i+1]<primero[i]){
            cout<<(n-i-1)<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
        
/*  FenwickTree tree(n);
    tree.add(primero[0],1);
    int ans = 0;
    For(i,n-1){
        tree.add(primero[i+1],1);
        D(tree.query(primero[i+1],n-1));
        ans += tree.query(primero[i+1],n-1);
    }
    cout<<ans<<endl;
/*  int ans = 0 ;
    For(i,n-1){
        ans += segundo[primero[i]] +1 == segundo[primero[i+1]] or segundo[primero[i]] == i;
    }
    D(ans);
    cout<<(n-ans)<<endl;*/
    
    return 0;
}