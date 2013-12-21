using namespace std;
#include<bits/stdc++.h>


string solve(){
    

    int n;cin>>n;
    int left = n-1, right = 0, upper = n-1, bottom = 0;
    char grid[n][n];
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin>>grid[i][j];
            if(grid[i][j] == '#'){
                left   = min(left, j);
                right  = max(right, j);
                upper  = min(upper, i);
                bottom = max(bottom, i);
            }
        }
    }
    
    int ok = (right - left) == (bottom - upper);
    
    for(int i = upper; i <= bottom ; ++i)
        for(int j = left;  j <= right; ++j)
            ok = ok and (grid[i][j] == '#');

    return ok ? "YES" : "NO";

}


int main(){
    int t;cin>>t;
    
    for(int i = 0; i < t; ++i)
        cout<<"Case #"<<(i+1)<<": "<<solve()<<endl;
        
    return 0;
}
