
using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

int main(){ ___

    int n,m,k;
    cin>>n>>m>>k;
    int ans[n][n]; // the shortest distance for a pair of vertexes i, j
    int a[k];  // vertexes, marked by Valera

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j)
                ans[i][j] = 0;
            else
                ans[i][j] = 1<<30;  //INF is a very large number 
        }
    }    
    
    For(i,k){
        cin>>a[i];
        a[i]--;
    }
    
    for(int i = 1; i <= m; i++) {
        int u,v;cin>>u>>v;
        u--;v--;
        ans[u][v] = 1;
        ans[v][u] = 1;
    }

    for (int i = 0; i < k; i++) {
        int v = a[i];
        for(int j = 0; j < n; j++)
            for(int r = 0; r < n; r++)
                ans[j][r] = min(ans[j][r], ans[j][v] + ans[v][r]);
    }
    
    for(int j = 0; j < n; j++){
            for(int r = 0; r < n; r++)
                cout<<ans[j][r]<<" ";
            cout<<endl;
    }
    return 0;
}
