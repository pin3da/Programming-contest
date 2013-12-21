using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXS 1000000


const double pi=acos(-1);


int main(){
    int tam;cin>>tam;
    string mio;cin>>mio;
    int ans=0,pin=0,sz=tam;
    char pp='B';
    int as=0,bs=0;
    For(i,sz-1){
        if(mio[i]=='A'&&mio[i+1]=='B')as++;
        if(mio[i]=='B'&&mio[i+1]=='A')as++;
    }
    for(tam--;tam>=0;tam--){
        pin=0;int cont=0;
        while(mio[tam]==pp&& tam>0 && mio[tam-1]==pp){
            ++cont;
            tam--;
            pin|=1;
        }
        Dbg{
            D(cont);
            D(tam);
            D(mio[tam]);
        }
        if( tam>1 && mio[tam-1]!=mio[tam-2] && pin){
            ans++;
        }
        if(tam==1){
            if(mio[tam]==pp || mio[tam-1]==pp){
                ans++;
                continue;
            }
        }

        if(pin){
            ans++;
            if(pp=='B')pp='A';
            else pp='B';
        }
    }
    //if(ans%2==0 && mio[0]=='B')ans++;
    cout<<ans<<endl;

    return 0;
}
