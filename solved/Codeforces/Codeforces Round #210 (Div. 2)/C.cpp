// http://codeforces.com/contest/361/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end

const int inf = (int)1e9 + 10;

struct s{
    int a,b,c,d;
    s(){}
};


int main(){ ___

    int n,m;
    while(cin>>n>>m){
        
        vector<s> input(m);
        vector<int> ans(n+1,inf);
        vector<int> acum(n+1,0);
        
        for(int i = 0; i< m; ++i){
            s &t = input[i];
            cin>>t.a>>t.b>>t.c>>t.d;
            if(t.a==1){
                for(int j = t.b; j <= t.c; ++j)
                    acum[j] += t.d;
            }else{
                for(int j = t.b; j <= t.c; ++j)
                    ans[j] = min(ans[j], t.d - acum[j]);
            }
        }
        
        for(int i = 1; i <= n; ++i ){
            if(ans[i] == inf) ans[i] = 0;
            acum[i] = ans[i];      
        }
        
        int valid = 1;
        
        for(int i = 0; i< m; ++i){
            s &t = input[i];
            
            if(t.a == 1){
                for(int j = t.b; j <= t.c; ++j)
                    acum[j] += t.d;
            }else{
                int mmax = acum[t.b];
                for(int j = t.b; j <= t.c; ++j)
                    mmax = max(mmax, acum[j]);
                if(mmax != t.d){
                    valid = 0;
                    break;
                }
            }
        }
        
        if(valid){
            cout<<"YES"<<endl;
            for(int i = 0; i < n; ++i){
                if(i)cout<<" ";
                cout<<ans[i+1];
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}