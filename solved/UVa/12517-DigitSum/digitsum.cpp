/***
* Manuel Pineda
* Accepted , 0.625 s
*/
using namespace std;
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
ll dp[11][2];
ll pow10[] = {1LL,10LL,100LL, 1000LL, 10000LL, 100000LL , 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL};

ll solve1(int index,int tope,string &num){
    if(index== num.size()) return 1;
    if(tope) return to_int(num.substr(index)) + 1;
    return pow10[num.substr(index).size()];
}

ll solve(int index,int tope,string &num){
    if(index==num.size()) return 0;
    if(dp[index][tope]!=-1) return dp[index][tope];
    int mmax = (tope)? to_int(num[index]):9;
    ll ans = 0;
    for(int i=0; i<=mmax;++i){
        ans += solve(index+1, (i==mmax)and tope,num) + i*solve1(index+1, (i==mmax)and tope,num);
        ll t = solve1(index, (i==mmax)and tope,num);
    }
    return dp[index][tope] = ans;
}

int main(){
    int a,b;
    while(cin>>a>>b and a+b){
        memset(dp,-1,sizeof(dp));
        string cad = to_str(a-1);
        ll p = solve(0,1,cad);
        memset(dp,-1,sizeof(dp));
        cad = to_str(b);
        ll s = solve(0,1,cad);
        cad = to_str(4);
//        D(solve1(0,1,cad));
        cout<<s-p<<endl;
    }
    return 0;
}
