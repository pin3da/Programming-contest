using namespace std;
#include <iostream>
#include <string>

int main(){
    int s;
    while(cin>>s and s){
        string cad;cin>>cad;
        if(cad.find("Z")!= string::npos){
            cout<<0<<endl;
        }else{
            int ans = 1<<30;
            int tmp = -1;
            for(int i = 0; i< cad.size(); ++i){
                if(cad[i] == 'R') tmp = i;
                if(cad[i] == 'D' and tmp != -1)
                     ans = min(ans, i-tmp);
                
            }
            tmp = -1;
            for(int i = 0; i< cad.size(); ++i){
                if(cad[i] == 'D') tmp = i;
                if(cad[i] == 'R' and tmp != -1)
                     ans = min(ans, i-tmp);
                
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
