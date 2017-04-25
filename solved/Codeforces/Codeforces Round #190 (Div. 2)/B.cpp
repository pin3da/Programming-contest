// http://codeforces.com/contest/322/problem/B

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
#define MAXNODES 100

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<ll> lucky;
void gen_lucky(ll a=0){
    if(a>1000000000L) return;
    ll x = (a*10) + 4;
    ll y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}

int main(){
    ll a,b,c;
    while(cin>>a>>b>>c){
        ll ans = a/3LL;
        ans += b/3LL;
        ans += c/3LL;
        ans += min(min(a%3LL,b%3LL),c%3LL);
        
        ll k = min(a,min(b,c));
        ll aa = a - k;
        ll bb = b - k;
        ll cc = c - k;
        ll ans2 = k + (aa/3LL) + (bb/3LL) + (cc/3LL);
        
        For(i, min(k,100000LL)){
            aa = a - (ll)i;
            bb = b - (ll)i;
            cc = c - (ll)i;
            ans2 = i+ (aa/3LL) + (bb/3LL) + (cc/3LL) + min(min(aa%3LL,bb%3LL),cc%3LL);
            ans = max(ans,ans2);
        }
        ans = max(ans,ans2);
        cout<<ans<<endl;
    }
    
    
    return 0; 
}