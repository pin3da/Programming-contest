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
    ll a,b;
    string moves;
    int dirx = 1;
    int diry = 1;
    while(cin>>a>>b>>moves){
        ll x = 0;
        ll y = 0;
        if(a< 0) {
            dirx = -1;
            a = -a;
        }
        if(b< 0) {
            diry = -1;
            b = -b;
        }
        if(a== 0 and b== 0){
            cout<<"Yes"<<endl;
            continue;
        }
        For(i,moves.size()){
            if(moves[i]=='U')y+= diry;
            if(moves[i]=='D')y-= diry;
            if(moves[i]=='R')x+= dirx;
            if(moves[i]=='L')x-= dirx;
        }
        
        ll lo = 0,hi = 1e9;
        while(lo<hi){
            ll mid = (lo+hi)/2;
            if(mid*x > a){
                hi = mid -1;
            }else{
                lo = mid;
            }
            if(lo == hi-1){
                hi = lo;
            }
        }
        
        D(lo);
        x*=lo;
        y*=lo;

        For(i,moves.size()){
            if(x == a and y == b)
                break;
            
            if(moves[i]=='U')y+= diry;
            if(moves[i]=='D')y-= diry;
            if(moves[i]=='R')x+= dirx;
            if(moves[i]=='L')x-= dirx;
        }
        
        if(x == a and y == b){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        /*
        
        if(paila)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;*/
        
    }
    
    
    return 0; 
}
