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
#include<cctype>

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
const double eps = 1e-9;
typedef long long int lli;
typedef pair<int , int> pii;

int main(){
    lli d;
    while(cin>>d and d){
       lli lo = 1;
       lli hi = 4294967250LL;
       lli ans = 1;
       while(lo < hi) {
           if(lo +1 == hi){
               lli a = (lo*(lo+1))>>1;
               lli b = (hi*(hi+1))>>1;
               if(a==d) ans = lo;
               else ans = hi;
               break;
           }
           lli mid = (lo + hi)>>1;
           lli fmid = (mid*(mid+1))>>1;
           if(fmid > d) hi = mid;
           else if (fmid < d) lo = mid;
           else {ans = mid;break;}
       }
       
       lli dis = ((ans*(ans+1))>>1) - d;
//       D(ans);
       lli row = ans - dis;
       lli col = dis +1;
       if(ans&1)swap(row,col);
       cout<<row<<" "<<col<<endl;
    
    }
    
    return 0;
}
