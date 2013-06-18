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

int main(){
    ll m;cin>>m;
    int primero = 0;
    ll a = -1,b = -1;
    int aaaa[] = {0,1,2,6};
    if(m<=3){
        cout<<aaaa[m]<<endl;
        return 0;
    }
    ll n;
    ll ans = -1;
    /*
    For(k,3){
        n = m -k;
        primero = 0;
        a = b = -1;
        for(ll i = n-1; i>=1; i--){
            if(!primero){
                if(gcd(i,n) == 1){
                    primero = 1;
                    a = i;
                }
            }else{
                if(gcd(i,a)==1 or gcd(i,n)==1){
           //         if(a*b*n < a*i*n)
                        b = i;
                    break;
                }
            }
        }
        ans = max(ans, (n*((a*b)/gcd(a,b))/gcd(((a*b)/gcd(a,b)),n)));
        D(a);
        D(b);
        D(n);
        D((n*((a*b)/gcd(a,b))/gcd(((a*b)/gcd(a,b)),n)));
    }
    /*
    D(a);
    D(b);
    D(n);
    D(gcd(gcd(a,b),n));*/
    For(i,min(m,2LL)){
        For(j,min(m,2LL)){
            For(k, min(m,2LL)){
                ll a = m - i;
                ll b = m - j;
                ll c = m - k;
                ans = max(ans, (c*((a*b)/gcd(a,b))/gcd(((a*b)/gcd(a,b)),c)));
            }
        }
    }
    cout<<ans<<endl;
    
    return 0; 
}

