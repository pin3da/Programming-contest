// NOT SOLVED YET !
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;


void extended_euclid(ll a, ll b, ll &x, ll &y, ll &g) {
    x = 0; y = 1; g = b;
    ll m, n, q, r;
    for (ll u=1, v=0; a != 0; g=a, a=r) {
        q = g / a; r = g % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}



ll chinese_remainder_theorem(vector<ll> ns, vector<ll> as){
    int k  = ns.size();
    ll N = 1, x = 0, r, s, g;
    for (int i = 0; i < k; ++i) N *= ns[i];
    for (int i = 0; i < k; ++i) {
        extended_euclid(ns[i], N/ns[i], r, s, g);
        x += as[i]*s*(N/ns[i]);
        x %= N;
    }
    if (x < 0) x += N;
    return x;
}

int main(){ ___
    
    int tc;cin>>tc;
    for(int tid = 1; tid<=tc; ++tid){
        ll n;cin>>n;
        
        vector<ll> x(n);
        vector<ll> a(n);
        
        for(int i = 0; i< n; ++i)
            cin>>x[i]>>a[i];
        
        printf("Case %lld: %lld\n",tid,chinese_remainder_theorem(x,a));
        
    }
    
    return 0;
}
