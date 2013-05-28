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

int M[100][100];

int main(){
    For(i,100){
        For(j,100){
            if((i%2 == 0) and (j%2 != 0)) M[i][j]=1;
            if((j%2 == 0) and (i%2 != 0)) M[i][j]=1;
        }
    }
    map<int,int> ans;
    For(k,100){
        int cont = 0;
        For(i,k){
            For(j,k){
                if(k%2)
                    cont+=M[i+1][j];
                else
                    cont+=M[i][j];
            }
        }
        ans[cont] = k;
    }
    ans[2] = 3;
    ans[3] = 5;
    int n;
    cin>>n;
    cout<<(ans.lower_bound(n)->second)<<endl;

    return 0;
    
}
