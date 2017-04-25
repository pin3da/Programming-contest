// http://codeforces.com/contest/60/problem/A

using namespace std;
#include<bits/stdc++.h>


int main(){
    int n,m;
    string buffer;
    while(getline(cin,buffer)){
        stringstream ss(buffer);
        ss>>n>>m;
        int izq = 1;
        int der = n;
        int paila = 0;
        for(int i = 0; i< m; ++i){
            getline(cin,buffer);
            stringstream s(buffer);
            string dir;
            s>>buffer>>buffer>>dir>>buffer;
            int pos;s>>pos;
            if(dir=="left"){
                der = min(der,pos-1);
            }else{
                izq = max(izq,pos+1);
            }
            if(der<izq)paila = 1;
        }
        if(paila)cout<<-1<<endl;
        else cout<<der-izq+1<<endl;
    }
    
    return 0;
}
