// http://codeforces.com/contest/178/problem/A1

using namespace std;
#include<bits/stdc++.h>

#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define For(i,n) for(int i =0 ; i < (n); ++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 10000

int main(){ ___
    int n;cin>>n;
    vector<int> data(n);
    For(i,n)cin>>data[i];
    
    vector<int> tmp(n);
    
    For(k,n-1){
        For(j,n) tmp[j] = data[j];
        int ans = 0;
        For(i,k+1){
            
            int next_index = 1;
            while(next_index*2 + i < n)next_index<<=1;
            tmp[next_index + i] += tmp[i];
            ans += tmp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}