// http://codeforces.com/contest/359/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end

int mat[60][60];

int main(){ ___
    int n,m;
    while(cin>>n>>m){
        int border = 0;
        for(int i = 0; i< n; ++i){
            for(int j = 0; j< m; ++j){
                cin>>mat[i][j];
                if(mat[i][j] and (i==0 or j==0 or (i==n-1) or (j==m-1))){
                    border = 1;
                }
            }
        }            
        if(border)cout<<2<<endl;
        else cout<<4<<endl;
    
    }
    return 0;
}