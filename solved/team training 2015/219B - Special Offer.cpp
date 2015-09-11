#include<bits/stdc++.h>
typedef long long ll;   
using namespace std;

int countNines(ll x){
    int r = 0;
    while(x%10 == 9){
        r++;
        x /= 10;
    }
    return r;
}

int main(){
    ll x, d;
    while( cin >> x >> d){
        ll ans = 1, xt = x,anst = x,ansf = x;
        ll p = 1;
        bool f = 0;
        while(ans <= d){
            
            if(xt % 10 != 9){
                if(f){
                    ans += (xt%10)*p;
                }else{
                    ans = (xt%10 + 1)*p;
                    f = 1;
                }
                
                xt /= 10;
                p *= 10;
                if(ans <= d)
                    anst = x - ans;
            }else{
                if(f){
                    ans += (9)*p;
                }else{
                    ans *= (10);                    
                }
                xt /= 10;
                p *= 10;
                if(ans <= d)
                    anst = x - ans;
            }
            
            int n1 = countNines(anst);
            int n2 = countNines(ansf);
            
            if(n1 > n2)
                ansf = anst;
        }
        cout << ansf << endl;
    }
}
