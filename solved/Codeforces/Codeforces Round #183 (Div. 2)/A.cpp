// http://codeforces.com/contest/304/problem/A

using namespace std;
#include<bits/stdc++.h>

#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define For(i,n) for(int i =0 ; i < (n); ++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);


int main(){ ___
    
    int n;cin>>n;
    int ans = 0;
    for(int i = 1; i <= n; ++i ){
        for(int j = i ; j <= n; ++j){
            int num = sqrt(i*i + j*j);
            if(num >= j and num <= n and i*i + j*j == num*num)
                ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}