/**
* Manuel Pineda.
* Accepted.
* 1.869 s
*/

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
#define MAX(a,b) ((a>b)?(a):(b))

typedef pair<int,int> pii;

int main(){
    int a,b,c,cid=0;
    while(cin>>a>>b>>c and a+b+c){
        vector<pii> datos(a);
        int tmp;
        For(i,a){
            cin>>tmp;
            datos[i]= make_pair(tmp,i);
        }
        sort(all(datos));
        cout<<"Case "<<++cid<<endl;
        vector<int> menor;
        vector<int> mayor;
        For(i,b)
            menor.push_back(datos[i].second+1);
        For(i,c)
           mayor.push_back(datos[a-i-1].second+1);
        
        sort(all(menor));
        sort(rall(mayor));
        For(i,b)
            cout<<menor[i]<<((i!=b-1)?" ":"\n");
        
        For(i,c)
            cout<<mayor[i]<<((i!=c-1)?" ":"\n");
        
        
    }
	return 0;
}
