// http://codeforces.com/contest/151/problem/B

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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


int is_taxy(string a){
    char p = a[0];
    For(i,a.size()){
        if((i+1)%3){
            if(p!=a[i]) return 0;
        }
    }
    return 1;
}

int is_pizza(string a){
    char p = '9'+1;
    For(i,a.size()){
        if((i+1)%3){
            if(p<=a[i]) return 0;
            p=a[i];
        }
    }
    return 1;
}

void mpr(vector<string> a){
    For(i,a.size())
        cout<<a[i]<<((i==a.size()-1)?"":", ");
}

int main(){
    int n;cin>>n;
    vector<string> taxi,pizza,nenas;
    int mt=0,mp=0,mn=0;
    For(i,n){
        int k;cin>>k;
        string nombre;cin>>nombre;
        string num;
        int ta=0,pi=0,ne=0;
        For(j,k){
            cin>>num;
            if(is_taxy(num))
                ta++;
            else if(is_pizza(num))
                pi++;
            else
                ne++;
        }
  /*      D(nombre);
        D(ta);
        D(pi);
        D(ne);*/
        if(ta >= mt){
            if(find(all(taxi),nombre)== taxi.end()) taxi.push_back(nombre);
            if(ta > mt){
                taxi.clear();
                taxi.push_back(nombre);
                mt = ta;
            }
        }
        if(pi >= mp){
            if(find(all(pizza),nombre)== pizza.end()) pizza.push_back(nombre);
            if(pi > mp){
                pizza.clear();
                pizza.push_back(nombre);
                mp = pi;
            }
        }        
        if(ne >= mn){
            if(find(all(nenas),nombre)== nenas.end()) nenas.push_back(nombre);
            if(ne > mn){
                nenas.clear();
                nenas.push_back(nombre);
                mn = ne;
            }
        }
    
    }

    cout<<"If you want to call a taxi, you should call: ";mpr(taxi);cout<<"."<<endl;
    cout<<"If you want to order a pizza, you should call: ";mpr(pizza);cout<<"."<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";mpr(nenas);cout<<"."<<endl;
    
    return 0;
}