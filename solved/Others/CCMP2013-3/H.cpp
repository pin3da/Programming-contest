using namespace std;
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<cstdio>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(it,x) for(typeof((x).begin()) it  = (x).begin(); it != (x).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

map<string,vector<string> > todos;

struct mio{
    string cad;
    int cuantos;
    mio(string C,int j):cad(C),cuantos(j){}
    bool operator<(const mio &o) const{
        if(cuantos == o.cuantos) return todos[cad][0] > todos[o.cad][0];
        return cuantos < o.cuantos;
    }
};

void mpr(vector<string> vv){
    sort(all(vv));
    set<string> impreso(all(vv));
/*    cout<<vv[0]<<((0==vv.size()-1)?" .\n":" ");
    For(i,vv.size()-1){
        if(vv[i]==vv[i+1])
            cout<<vv[i+1]<<((i+1==vv.size()-1)?" .\n":" ");
    }*/
    int i=0;
    foreach(x,impreso){
        cout<<(*x)<<((i==impreso.size()-1)?" .\n":" ");
        ++i;
    }
}

int main(){
    string cad;

    map<string,int> cod;
    vector<mio> cantidad;
    while(cin>>cad){
        string s2 = cad;
        sort(all(s2));
        todos[s2].push_back(cad);
        if(cod.count(s2)>0){
            cantidad[cod[s2]].cuantos++;
        }else{
            cantidad.push_back(mio(s2,1));
            cod[s2] = cantidad.size()-1;
        }
    }
    
    sort(rall(cantidad));
    
    map<int, vector<string> > ans;
    
    vector<string> unitario;
    For(i,cantidad.size()){
        if(cantidad[i].cuantos == 1)
             unitario.push_back(todos[cantidad[i].cad][0]);

    }
    foreach(xx,ans){
        sort(all(xx->second));
    }
    int i;

    for(i =0;i<5 and i<(cantidad.size()-unitario.size());++i){
            cout<<"Group of size "<<cantidad[i].cuantos<<": ";
            mpr( todos[cantidad[i].cad] );
    }
    sort(all(unitario));
    int pos =0;
    
    while(i<5 and pos<unitario.size()){
        cout<<"Group of size 1: "<<unitario[pos++]<<" ."<<endl;
        ++i;
    }
    
}

