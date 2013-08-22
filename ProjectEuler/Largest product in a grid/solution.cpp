using namespace std;
#include<bits/stdc++.h>
#define MP 20

int dx[4][4] = {{0,0,0,0},{0,1,2,3},{0,1,2,3},{0,1,2,3}};
int dy[4][4] = {{0,1,2,3},{0,0,0,0},{0,1,2,3},{0,-1,-2,-3}};

int main(){
    int grid[MP][MP];
    for(int i = 0; i< MP; ++i)
        for(int j = 0; j< MP; ++j)
            cin>>grid[i][j];
            
    
    int ans = 0;
    
    for(int i = 0; i< MP; ++i){
        for(int j = 0; j< MP; ++j){
            for(int k = 0; k< 4; ++k){
                int ok = 1;
                int tmp = 1;
                for(int m = 0; m< 4; ++m){
                    int x = i + dx[k][m];
                    int y = j + dy[k][m];
                    if(x >= 0 and x < 20 and y >= 0 and y < 20)
                        tmp *= grid[x][y];
                    else
                        ok = 0;
                }
                if(ok) ans = max(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
