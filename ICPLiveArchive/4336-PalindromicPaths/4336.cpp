using namespace std;
#include<iostream>

char G[55][55];

strign solve(int i,int j){
    if(j==i) return "";
    
    

}

int main(){
    int tc;cin>>tc;
    int n;
    while(tc--){
        cin>>n;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>G[i][j]
                
        cout<<solve(0,n-1)<<endl;
    }
    return 0;
}
