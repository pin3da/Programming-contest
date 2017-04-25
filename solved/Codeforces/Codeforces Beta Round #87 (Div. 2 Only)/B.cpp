// http://codeforces.com/contest/116/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 11


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){ ___
    int n,m;cin>>n>>m;
    char grid[n][m];
    int see[n][m];
    for(int i = 0; i< n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>grid[i][j];


    
    int ans = 0;
    
    for(int i = 0; i< n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j]=='W'){
                int ok = 0;
                for(int k = 0; k< 4; ++k){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 and x < n and y >= 0  and y < m){
                        if(grid[x][y] == 'P')
                            ok = 1;
                    }
                }
                if(ok)ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

