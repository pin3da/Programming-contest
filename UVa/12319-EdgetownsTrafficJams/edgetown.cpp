/**
* Manuel Pineda
* Accepted, 0.482
*/
using namespace std;
#include <string>
#include <sstream>
#include <iostream>

#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXNODES 101

template<class T> int to_int(T t){ stringstream ss; ss<<t; int r; ss>>r; return r; }
template<class T> string to_str(T t){ stringstream ss; ss<<t; return ss.str(); }

int n;
unsigned long long g[MAXNODES][MAXNODES];
unsigned long long g2[MAXNODES][MAXNODES];

void floyd(){
  for (int k=0; k<n; ++k){
    for (int i=0; i<n; ++i){
      for (int j=0; j<n; ++j){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
      }
    }
  }
}

int main(){
    string buffer;
    while(getline(cin,buffer)){
        n =  to_int(buffer);
        if(n==0) break;
        
        for(int i = 0; i < MAXNODES; ++i)
            for(int j = 0; j < MAXNODES; ++j){
                g[i][j] = (1<<30);
                g2[i][j] = (1<<30);
            }
                
        for(int i = 0; i< n; ++i){
            getline(cin,buffer);
            stringstream ss(buffer);
            ss>>buffer;
            int u = to_int(buffer);
            while(ss>>buffer){
                int v = to_int(buffer);
                g[u-1][v-1] = 1;
            }
        }
        
        for(int i = 0; i< n; ++i){
            getline(cin,buffer);
            stringstream ss(buffer);
            ss>>buffer;
            int u = to_int(buffer);
            while(ss>>buffer){
                int v = to_int(buffer);
                g2[u-1][v-1] = 1;
            }
        }
        getline(cin,buffer);
        stringstream ss(buffer);
        int a; ss>>a;
        int b; ss>>b;
        
        floyd();
        
        int paila = 0;
        
        for(int i = 0; i <= n and !paila; ++i){
            for(int j = 0; j <= n and !paila; ++j){
                if(j==i or g[i][j]==(1<<30)) continue;
                if((g[i][j]*a + b) < g2[i][j]){
                    paila = 1;
                }
            }
        }
        
        cout<<((paila)?"No":"Yes")<<endl;

        
        
    }
    return 0;
}
