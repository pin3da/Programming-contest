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
    return query(to) - query(from-1);
  }

};



int is_pal(lli a){
  string cad = toStr(a);
  int t = cad.size()/2;
  For(i,t) if(cad[i]!=cad[cad.size()-i-1]) return 0;
  return 1;
}

int main(){
    FenwickTree tree(10000005);
    for(lli i=1;i<10000005;++i)
      if(is_pal(i) and is_pal(i*i))
        tree.add(i,1);
    
    int tc;cin>>tc;
    For(i,tc){
      lli a,b;cin>>a>>b;
      a = ceil (sqrt(a));
      b = floor (sqrt(b));
      cout<<"Case #"<<(i+1)<<": "<<tree.query(a,b)<<endl;
      
    }
    return 0;
}   
