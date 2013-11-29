/**
    Wrong answer
*/

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010

int n,k,l,r,sa,sk;

int main(){ ___


    while(cin>>n>>k>>l>>r>>sa>>sk){
        vector<int> ans(n);
        for(int i = 0; i< n; ++i){
            ans[i] = l;
        }
        
        int cur = l*k;
        
        int cant_el = ceil((sk - cur)/(double)k);
        assert(l+cant_el <= r);
       
        int i = 0;
        while(i < n and cur < sk){
            int sum = cant_el;
            int falta = sk - cur;
            if(sum > falta) sum = falta;
            cur += sum;
            ans[i] += sum;
            ++i;
        }
        
        if(cur != sk){
            cout<<"Bad k"<<endl;
            retrun 0;
        }
        
        cur += (n-k)*l;
        
        //D(cur);
        i = k;
        int mio  = ans[i-1];
        while(i < n and cur < sa){
            int sum = mio - ans[i];
            int falta = sa - cur;
            if(falta < sum) sum = falta;
            cur += sum;
            ans[i] += sum;
            ++i;
        }
                
        assert(cur == sa);
        
        for(int i = 0; i< ans.size(); ++i){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
