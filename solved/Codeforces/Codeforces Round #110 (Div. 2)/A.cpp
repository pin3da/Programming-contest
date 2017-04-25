// http://codeforces.com/contest/157/problem/A

//http://codeforces.com/problemset/problem/157/A
using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl

int main(){
    int n;
    while(cin>>n){
        int mat[n][n];
        
        for(int i =0 ; i< n; ++i)
            for(int j = 0; j< n; ++j)
                cin>>mat[i][j];

        
        int ans = 0;
        
        for(int i =0 ; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int a = 0;
                int b = 0;
                for(int k = 0; k < n; ++k){
                    a += mat[i][k];   
                    b += mat[k][j];    
                }
                if(b > a) ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
