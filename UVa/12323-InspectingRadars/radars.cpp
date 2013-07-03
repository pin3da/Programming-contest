/**
*  Manuel Pineda
*  Acc , 1.958
*  Key_Idea:
*      Use an integral image (Aplication of inclusion-exclusion principe)
*/

using namespace std;
#include <iostream>
#include <cstring>
#include <algorithm>

int n,r;
int mat[360*2 + 10][110];
int sum[360*2 + 10][110];

void fill_sum(){
    for (int i = 0; i < 720; ++i) {
        for (int j = 0; j < 101; ++j) {
            sum[i][j] = mat[i][j];
            if (i > 0) sum[i][j] += sum[i-1][j];
            if (j > 0) sum[i][j] += sum[i][j-1];
            if (i > 0 and j > 0) sum[i][j] -= sum[i-1][j-1];
        }
    }
}

int query(int r1, int c1, int r2, int c2) {
    int ans = sum[r2][c2];
    if (r1 > 0) ans -= sum[r1-1][c2];
    if (c1 > 0) ans -= sum[r2][c1-1];
    if (r1 > 0 and c1 > 0) ans += sum[r1-1][c1-1];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin>>n>>r and n+r){
        int a,b;
        memset(mat,0,sizeof mat);
        
        for(int i = 0; i< n; ++i){
            cin>>a>>b;
            mat[b][a]++;
            mat[b+360][a]++;
        }
        
        fill_sum();
        
        int e;cin>>e;
        int H,A;
        
        while(e--){
            cin>>H>>A;
            int ans = 0;
            H--;
            for (int i = 0; i + H < 101; ++i) 
                for (int j = 0; j + A < 720; ++j)
                    ans = max(ans, query(j, i, j + A, i + H));
                
            cout<<ans<<endl;
        }
        
    
    }
    return 0;
}
