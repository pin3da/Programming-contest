// http://codeforces.com/contest/74/problem/A

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


int main(){
    int n;cin>>n;
    string ans;
    int suma= -(1<<30);
    For(i,n){
      string nombre;cin>>nombre;
      int pos;cin>>pos;
      int neg;cin>>neg;
      int var=0;
      int t;
      For(j,5){
          cin>>t;
          var+=t;
      }      
      
      if(pos*100 -neg*50 + var > suma){
          ans = nombre;
          suma  = pos*100 -neg*50 + var;
      }
    }
    
    cout<<ans<<endl;
    

}