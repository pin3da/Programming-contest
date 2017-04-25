// http://codeforces.com/contest/168/problem/B

using namespace std;
#include<iostream>
#include<sstream>
#include<string>


int main(){
    string cad;
    string linea = "";
    int abre = 0;
    int blanco = 0;
    while(getline(cin,cad)){
        stringstream ss(cad);
        string tmp; ss>>tmp;
        if(tmp.size()>0 and tmp[0]=='#'){
            if(blanco) cout<<endl;
            cout<<cad<<endl;
            blanco = 0;
        }else{
            tmp = linea = "";
            stringstream b(cad);
            while(b>>tmp){
                if(linea.size()==1 and linea[0]=='\n') linea="";
                linea+=tmp;
            }
            cout<<linea;
            blanco = 1;
        }
        //if(!abre and !algo and blanco)cout<<endl;
    }
    if(blanco)cout<<endl;
    return 0;
    
}