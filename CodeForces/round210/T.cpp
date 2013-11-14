using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end


int main(){ ___

    int n,k;
    while(cin>>n>>k){
        int ans = 0;
        int tmp;
        for(int i = 0; i< n; ++i){
            cin>>tmp;
            if(__gcd(tmp,i+1)>1)ans++;
        }
        if(ans == k)
            cout<<"Correct"<<endl;
        else
            cout<<"Wrong"<<endl;
    }

    return 0;
}
