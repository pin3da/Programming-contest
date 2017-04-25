// http://codeforces.com/contest/102/problem/A

using namespace std;
#include <bits/stdc++.h>
#define MP 101

int match[MP][MP];
long long price[MP];

int main(){
    int n,m;cin>>n>>m;
    for(int i = 0 ; i< n; ++i)cin>>price[i];
    int a,b;
    for(int i = 0 ; i< m; ++i){
        cin>>a>>b;
        a--;b--;
        match[a][b] = match[b][a] = 1;
    }
    long long ans = (1LL<<60);
    for(int i = 0 ; i< n; ++i)
        for(int j = 0 ; j< n; ++j)
            for(int k = 0 ; k< n; ++k)
                if(match[i][j] and match[i][k] and match[j][k])
                    ans =  min(ans, price[i]+price[j]+price[k]);
    
    if(ans == (1LL<<60))cout<<-1<<endl;
    else cout<<ans<<endl;

    
    return 0; 
}