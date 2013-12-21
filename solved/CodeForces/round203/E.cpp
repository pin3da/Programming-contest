using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

int main(){ ___
    int n,m,k;
    while(cin>>n>>m>>k){
        vector<int> marked(n);
        int t;
        For(i,k){
            cin>>t;
            marked[--t] = 1;
        }
        if( (m+1) != n){ 
            cout<<-1<<endl;
            continue;
        }
        
        int unmarked = -1;
        For(i,n){
            if(!marked[i]){ 
                unmarked = i;
                break;
            }
        }
        if(unmarked == -1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> used(n,0);
        used[unmarked] = 1;
        int cont = 0;
        int ant = 0;
        for(int i = 0; i< n and cont < 2; ++i){        
            if(marked[i]){
                cout<<(unmarked+1)<<" "<<(i+1)<<endl;
                cont++;
                used[i]++;
                ant = i;
            }
        }
        
        for(int i = 0; i< n; ++i){
            if(!used[i]){
                cout<<(ant+1)<<" "<<(i+1)<<endl;
                used[i]++;
                ant = i;
            }
        }
        
    }
    
    return 0;   
}
