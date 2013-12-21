using namespace std;
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define For(i,n) for(int  i= 0 ; i<n;++i)
#define D(x) cout<< #x " = " <<(x)<<endl


int main(){
    int a,b,c;
    while(cin>>a>>b>>c and a+b+c){
           vector<int> todos(a);
           For(i,a)cin>>todos[i];
           if(c>a){
                cout<<"NO"<<endl;
                continue;
           }
           sort(todos.rbegin(),todos.rend());
           int temporal = 0;
           For(i,c){
            temporal+= todos[i];
           }
           if(temporal > b)cout<<"NO"<<endl;
           else cout<<"YES"<<endl;
        
        
    }
    return 0;
}

