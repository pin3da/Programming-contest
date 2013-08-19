using namespace std;
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string cad;
    int a,b,q,tam;
    int ans;
    while(cin>>cad){
        if(cad[0]=='*')break;
        cin>>q;
        tam = cad.size();
        while(q--){
            cin>>a>>b;
            ans = 0;
            while(cad[a] ==cad[b] && b < tam){
                ans++;
                a++;
                b++;
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}

