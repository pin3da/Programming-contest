using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string cad;
    while(cin>>cad){
        for(int i = 0; i < cad.size(); ++i)
            if(cad[i] == '?')cad[i] = '0';

        int ans =  0, ok = 1, cuenta = 1;
        for(int i = 0 ; i< cad.size(); ++i){
            if(cad[i] == '0')
                cuenta--;
            else
                if(++cuenta > 1)
                    ok = false;     
            if(cuenta == 0){
                cuenta = 1;
                ok = true;
                ans++;
            }
        }
        if(ok && cuenta == 1) cout<<ans<<endl;
        else cout<<0<<endl;

        
    }
    return 0;
}
