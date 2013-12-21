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
#include<cassert>
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int , int> pii;

ull r,t;

ull fun(ull r,ull n){
    if (((2LL*n*r) + (2LL*n*(n+1)) + n) + 2LL*r + 1LL < r+n) return t+1LL;
    return ((2LL*n*r) + (2LL*n*(n+1)) + n) + 2LL*r + 1LL;
}

int main(){
    int nc;cin>>nc;
    for(int tid = 1; tid <= nc; ++tid){
        cin>>r>>t;
        ull lo = 0LL;
        ull hi = 707106780LL;
        while(lo < hi){
            if(lo+1 == hi){
                if(fun(r,hi) > t) hi = lo;
                break;
            }
            ull mid = (lo + hi)/2LL;
            if(fun(r,mid) > t)
                hi = mid;
            else
                lo = mid;
        }
        cout<<"Case #"<<tid<<": "<<(hi+1)<<endl;
        
    }
    
    return 0;
}
