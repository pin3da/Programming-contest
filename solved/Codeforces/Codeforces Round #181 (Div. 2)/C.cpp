// http://codeforces.com/contest/300/problem/C

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
typedef long long int lli;
typedef pair<int , int> pii;
typedef vector<int> vi;
lli fact[1000010];
const lli modulo = 1e9 + 7;

typedef vector<int> VI;
typedef pair<int,int> PII;

// return a % b (positive value)
lli mod(lli a, lli b) {
  return ((a%b)+b)%b;
}

// computes gcd(a,b)
lli gcd(lli a, lli b) {
  lli tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
lli extended_euclid(lli a, lli b, lli &x, lli &y) {  
  lli xx = y = 0;
  lli yy = x = 1;
  while (b) {
    lli q = a/b;
    lli t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
lli mod_inverse(lli a, lli n) {
  lli x, y;
  lli d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}


lli a,b,n;
lli is_excellent(lli ca,lli cb){
    lli otro=ca*a + cb*b;
    while(otro){
        if((otro%10) != a and (otro%10) != b) return 0;
        otro /=10;
    }
    return 1;
}
lli contar(lli x,lli y){
//    mod_inverse(f)
    lli tmp = (fact[x+y] * mod_inverse(fact[y],modulo))%modulo;
    tmp *= mod_inverse(fact[x],modulo);
    tmp %= modulo;
    return tmp;
 //return fact[x+y] /( fact[y]*fact[x]);

}
int main(){
    fact[0] = 1;
    For(i,1000005)
        fact[i+1] = (fact[i]*(i+1)%modulo);
        

    cin>>a>>b>>n;
    lli ans = 0;
    lli tengo,falta;
    For(i,n+1){
        tengo = i;
        falta = n -i;
        if(is_excellent(tengo,falta)){
            ans += (tengo==0 or falta==0)?1LL:contar(tengo,falta);
            ans%=modulo;
        }
    }
    cout<<ans<<endl;
    
    return 0;
    
}