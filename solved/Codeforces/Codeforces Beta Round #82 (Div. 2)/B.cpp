// http://codeforces.com/contest/106/problem/B

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

struct laptop{
    int speed, ram, hdd ,cost, index;
    laptop(int a,int b,int c,int d,int i): speed(a), ram(b),hdd(c), cost(d), index(i){}
    laptop(){}
    
    bool operator<(const laptop & o) const{
        if(speed < o.speed and ram < o.ram and hdd < o.hdd) return true;
        return false;
    }

};

bool my_cmp(laptop a, laptop b){
    return a.cost < b.cost;
}

int main(){
    int n;cin>>n;
    vector<laptop> todo;
    For(i,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        todo.push_back(laptop(a,b,c,d,i));
    }
    vector<laptop> ans;
    For(i,n){
        int pin = 1;
        For(j,n){
            if(todo[i]< todo[j]) pin = 0;
        }
        if(pin) ans.push_back(todo[i]);
    }
    sort(all(ans),my_cmp);
    cout<<ans[0].index+1<<endl;
    
    
    
    return 0;
    
}
