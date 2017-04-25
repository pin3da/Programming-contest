// http://codeforces.com/contest/57/problem/B

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
typedef long long int lli;
typedef pair<int , int> pii;


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<lli> lucky;
void gen_lucky(lli a=0){
    if(a>1000000000L) return;
    lli x = (a*10) + 4;
    lli y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}

const int MP = 100010;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[MP],b[MP],c[MP];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    For(i,m)
        cin>>a[i]>>b[i]>>c[i];
        
    lli ans = 0;
    For(i,k){
        int hasta;cin>>hasta;
        For(j,m)
            if(a[j] <= hasta and hasta <= b[j]) ans += c[j] + (hasta - a[j]);
    }
    cout<<ans<<endl;
    return 0;
    
}