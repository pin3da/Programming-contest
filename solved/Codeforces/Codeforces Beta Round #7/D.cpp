// http://codeforces.com/contest/7/problem/D

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

typedef unsigned long long hash;

long long ans[5000010];

string cad;
const int p1 = 1321;
vector<hash> h1,h2;
vector<hash> pi;

void comp_hash(){
    h1.resize(cad.size()+5);
    h2.resize(cad.size()+5);
    pi.resize(cad.size()+5);
    
    string dae = cad;
    reverse(dae.begin(), dae.end());
    
    pi[0] = 1;
    for(int i = 0; i< cad.size(); ++i){
       if(i) pi[i] = pi[i-1] * p1; 
    }
    
    for(int i = 0; i < cad.size(); ++i){
        h1[i] = cad[i] * pi[i];
        h2[i] = dae[i] * pi[i];
        if(i){
            h1[i] += h1[i-1];
            h2[i] += h2[i-1];
        }
    }
    
}

int cmp(int i){
    hash primero = h1[i];
    int desde = cad.size()-1 - i;
    int hasta = cad.size()-1;
    hash segundo = h2[hasta] - ((desde) ? h2[desde-1] : 0);
    return (primero * pi[desde]) == segundo;
    
}

long long solve(){
    memset(ans, 0, sizeof ans);
    ans[0] = 1;
    int n = cad.size();
    long long acum = 1;
    for(int i = 1; i < n; ++i){
        int m = i/2;
        if((i&1)==0) m--;
        if(cmp(i)){
            ans[i] = ans[m] + 1;
            acum += ans[i];
        }
    }
    
    return acum;
}


int main(){

    while(cin>>cad){
        comp_hash();
        cout<<solve()<<endl;
    }
    
    return 0;
}