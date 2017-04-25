// http://codeforces.com/contest/291/problem/B

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;

int main(){
    string line;getline(cin,line);
    int index = 0;
    int abierto = 0;
    string tmp,acum;
    while(index < line.size()){
        if(abierto){
            if(line[index]!='\"'){
                tmp+= line[index];
            }else{
                cout<<'<'<<tmp<<'>'<<endl;
                tmp="";
                abierto  =0;
            }
        }else{
            if(line[index]=='\"'){
                abierto = 1;
            }else if(line[index]==' '){
                if(acum.size()>0){
                    cout<<'<'<<acum<<'>'<<endl;
                    acum="";
                }
            }else{
                acum+=line[index];
            }
        }
        index++;
    }
    if(acum.size()>0)
        cout<<'<'<<acum<<'>'<<endl;
    
    
    return 0; 
}