// http://codeforces.com/contest/369/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010


int main(){ ___

    int n,m,k;
    while(cin>>n>>m>>k){
        int t;
        int ans = 0;
        while(n--){
            cin>>t;
            if(t==1){
                if(m==0)
                    ans++;
                else
                    m--;
            }else{
                if(k==0){
                    if(m==0)
                        ans++;
                    else
                        m--;
                }else{
                    k--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}