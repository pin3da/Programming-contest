using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define cl(x) memset(x, -1,sizeof x);

template<class T> string to_str(T t){stringstream ss; ss<<t; return ss.str();}

typedef long long ll;
ll a,b;
ll _dp[33][33][2][2];

ll dp(int index, int llevo, int tope, int puse, string &s){
    if(index == s.size()) return llevo;
    if(_dp[index][llevo][tope][puse] != -1) return _dp[index][llevo][tope][puse];
    ll ans = 0;
    int m = ((tope)? (s[index] - '0') : 9);
    for(int i = 0 ; i <= m; ++i)
        ans += dp(index + 1 , (puse ? (llevo + (i==0)) : 0) , tope and (i == (s[index] - '0')), (i != 0) or puse, s);
    return _dp[index][llevo][tope][puse] = ans;
}

void read(){cin>>a>>b;a--;}

void solve(int Case){
    string A = to_str(a);
    string B = to_str(b);
    cl(_dp);
    ll from = (a == -1)? -1 : dp(0,0,1,0,A);
    cl(_dp);
    ll to   = dp(0,0,1,0,B);
    cout<<"Case "<<Case<<": "<<(to - from)<<endl;
}

int main(){
    cin.sync_with_stdio(false);
    int t;cin>>t;
    for(int i = 0; i < t; ++i, read(),solve(i));
}
