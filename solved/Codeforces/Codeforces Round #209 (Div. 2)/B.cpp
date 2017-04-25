// http://codeforces.com/contest/359/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end

int mat[60][60];

int main(){ ___
    int n,k;
    while(cin>>n>>k){
        vector<int> ans(n*2);
        for(int i = 0; i < 2*n; ++i)
            ans[i] = i+1;
        
        int idx = 0;
        while(k--){
            swap(ans[idx],ans[idx+1]);
            idx+=2;
        }
        
        for(int i = 0; i< ans.size(); ++i){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;

    }
    return 0;
}