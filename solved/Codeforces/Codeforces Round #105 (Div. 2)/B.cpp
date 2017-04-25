// http://codeforces.com/contest/148/problem/B

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;

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
    double vp,vd,t,f,c;
    while(cin>>vp>>vd>>t>>f>>c){
        if(vp >= vd){
            cout<<0<<endl;
            continue;
        }
        
        double time = 0;
        double posp = t*vp;
        double posd = 0;
        int visajes = 0;
        while(posp < c){
            double to_reach = posp/(vd - vp);
            if((to_reach*vp + posp) >= c) break;
            visajes++;
            double devuelve = ((to_reach*vp + posp)/vd) + f;
            posp += (to_reach + devuelve)*vp;// devuelve*vp + f*vp;
        }
        cout<<visajes<<endl;
        
    
    }
    
    return 0; 
}