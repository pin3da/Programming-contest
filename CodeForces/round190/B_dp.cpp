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

ll dp[100][100][100];

ll solve(ll a, ll b, ll c){
    if(a + b + c== 0) return 0;
    ll ans = 0;
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    if(a > 0 and b > 0 and c > 0)
        ans = max(ans,1+ solve(a-1,b-1,c-1));
    
    if(a > 3)
        ans = max(ans,1+ solve(a-3,b,c));
    if(b > 3)
        ans = max(ans,1+ solve(a,b-3,c));
    if(c > 3)
        ans = max(ans,1+ solve(a,b,c-3));
    return dp[a][b][c] = ans;
}

int main(){
    ll a,b,c;
    while(cin>>a>>b>>c){
        memset(dp,-1,sizeof dp);
        cout<<solve(a,b,c)<<endl;
    }
    
    
    return 0; 
}
