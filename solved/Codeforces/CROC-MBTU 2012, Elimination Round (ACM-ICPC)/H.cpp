// http://codeforces.com/contest/245/problem/H

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
#define MAXNODES 100

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
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

int dp[5005][5005];
string cad;

int palindrome(int i,int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i>=j) return dp[i][j] = true;
    return dp[i][j] = (cad[i]==cad[j] and palindrome(i+1,j-1));
}

int dp1[5005][5005];
int count(int i,int j){
    if(dp1[i][j]!=-1) return dp1[i][j];
    if(j<i) return dp1[i][j] = 0;
    int ans = 0;
    if(palindrome(i,j)) ans++;
    ans += count(i+1,j);
    ans += count(i,j-1);
    ans -= count(i+1,j-1);
    return dp1[i][j] = ans;
}

int main(){
    cin>>cad;
    memset(dp,-1,sizeof(dp));
    memset(dp1,-1,sizeof(dp1));
    int queries;
    cin>>queries;
    For(kk,queries){
        int a, b;
        cin>>a>>b;
        a--;b--;
        cout<<count(a,b)<<endl;
    }
    
    return 0; 
}