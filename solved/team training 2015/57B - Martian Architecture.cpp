#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct road{
    int l,r,s;
    road(){}
    road(int _l,int _r,int _s):l(_l),r(_r),s(_s){}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int n,m,k,x;
    while( cin >> n >> m >> k){
        road roads[m];
        
        for(int i = 0; i < m; i++) cin >> roads[i].l >> roads[i].r >> roads[i].s;
        
        ll sol = 0;
        
        for(int i = 0; i < k; i++){
            cin >> x;

            for(int j = 0; j < m; j++){
                if(roads[j].l > x or roads[j].r < x) continue;

                sol += (x-roads[j].l) + roads[j].s;
            }
            
        }
        cout << sol << endl;
    }
    
    
}
