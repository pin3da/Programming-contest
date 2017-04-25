// http://codeforces.com/contest/94/problem/B

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



int main(){
    int n;cin>>n;
    int M[5][5];
    memset(M,0,sizeof(M));
    
    int a,b;
    For(i,n){
        cin>>a>>b;
        a--;b--;
        M[a][b] = M[b][a] = 1;
    }
    n = 5;
    int pin = 0;
    for(int i = 0; i< n; ++i)
        for(int j = i+1 ; j < n; ++j)
            for(int k = j+1; k < n ; ++k)
                if((M[i][j] and M[i][k] and M[j][k]) or  (!M[i][j] and !M[i][k] and !M[j][k]) )
                        pin = 1;
                

    if(pin)
        cout<<"WIN"<<endl;
    else
        cout<<"FAIL"<<endl;
    

    return 0;
    
}