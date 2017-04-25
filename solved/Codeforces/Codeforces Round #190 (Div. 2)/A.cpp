// http://codeforces.com/contest/322/problem/A

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
    int n,m;
    
    while(cin>>n>>m){
        vector<int> aviable(n,1);
        vector<int> aviable2(m,1);
        
        int i = 0, j = 0;
        int p = 0;
        vector<pair<int,int> > ans;
        while(i< aviable.size() and j  < aviable2.size()){
            ans.push_back(make_pair(i+1,j+1));
            if(i==aviable.size()-1) ++j;
            else if (j == aviable2.size()-1) ++i;
            else if(p) ++i;
            else ++j;
            p = !p;
        }
        cout<<ans.size()<<endl;
        foreach(it,ans){
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    
    
    return 0; 
}
