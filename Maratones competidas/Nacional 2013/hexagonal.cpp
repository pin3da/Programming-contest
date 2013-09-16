using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

void aligne(vector<int> &v, int t){
    while(v[0] != t){
        int tmp = v[0];
        for(int i = 0; i< 5; ++i)
            v[i] = v[i+1];
        v[5] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    while(cin>>t){
        vector<vector<int> > todos(7,vector<int>(6));
        todos[0][0] = t;
        for(int i = 1; i< 6; ++i)
            cin>>todos[0][i];
            
        for(int i = 1; i< 7; ++i)
            for(int j = 0; j < 6; ++j)
                cin>>todos[i][j];
                
        int _index[] = {0,1,2,3,4,5,6};
        
        
        vector<int> index(_index,_index+7);
        int ans = 0;
        do{
            for(int i = 1; i < 7; ++i)
                aligne(todos[index[i]],todos[index[0]][i-1]);
            
            int ok = 1;
            for(int i = 1; i< 7; ++i){
                int next = i+1;
                if(next == 7) next = 1;
                if(todos[index[i]][5] != todos[index[next]][1]) ok = 0;
            }
            
            if(ok){ 
                ans = 1;
                break;
            }
        
        }while(next_permutation(index.begin(),index.end()));
        
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
