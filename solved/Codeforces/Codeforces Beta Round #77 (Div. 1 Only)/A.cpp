// http://codeforces.com/contest/95/problem/A

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

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

string m_tolower(string a){
    For(i,a.size()) a[i]= tolower(a[i]);
    return a;
}

int is_lower(char x){
    if(x>= 'a' and x <='z') return 1;
    return 0;
}
string original;

string my_repleace(string cad,int desde,int cuantos,char c){
    For(i,cuantos){
        if(is_lower(cad[desde+i])) 
            if (tolower(original[desde+i]) != tolower(c) )
               cad[desde+i] = tolower(c);
            else{
//                D("entra");
                char aa='a';
                while(aa==c)++aa;
                cad[desde+i] = tolower(aa);
            }
                
        else 
            if (tolower(original[desde+i]) != tolower(c) )
               cad[desde+i] = toupper(c);
            else{ 
                char aa='a';
                while(aa==c)++aa;
                cad[desde+i] = toupper(aa);
            }
    }
    return cad;
}

int my_find(int ini,string cad,string forb){
    int i=ini+1;
    for(;i<cad.size();++i){
        int ok = 1;
        if(cad[i]==forb[0]){
            int j=0;
            for(;j<forb.size()and i+j<cad.size();++j){
                ok &= forb[j]==cad[i+j];
            }
            if(ok and j==forb.size())
                return i;
        }
    }
    return cad.size();
}

int main(){
    int n;cin>>n;
    vector<string> forbidden(n);
    For(i,n) cin>>forbidden[i];
    string cad;cin>>cad;
    char c;cin>>c;
    string cad2 = m_tolower(cad);
    original = cad;
    For(i,n){
        int pos = my_find(-1,cad2,m_tolower(forbidden[i]));//cad2.find(m_tolower(forbidden[i]));
        while(pos<cad.size()){
            cad = my_repleace(cad,pos,forbidden[i].size(),c);
            pos = my_find(pos,cad2,m_tolower(forbidden[i]));
        }
    }
    cout<<cad<<endl;
    
}