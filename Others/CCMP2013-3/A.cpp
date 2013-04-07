using namespace std;
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<map>
#include<set>

#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(it,x) for(typeof((x).begin()) it  = (x).begin(); it != (x).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

vector<string> sufi(string cad){
    stringstream buf(cad);
    vector<string> ans;
    string tmp;
    while(buf>>tmp){
        ans.push_back(tmp);
    }
    return ans;
}

string limpiar(string cad){
    string ans = "";
    For(i,cad.size()){
        if(cad[i]=='!' or cad[i]==',' or cad[i]=='.' or cad[i]==':' or cad[i]==';' or cad[i]=='?'  or cad[i]=='-')
            continue;
        if(i<cad.size()-1){
            if(cad.substr(i,2)=="¿"){
                i++;
                continue;
            }else if(cad.substr(i,2)=="¡"){
                i++;
                continue;
            }
        }
        ans.push_back(cad[i]);
    }
   
    stringstream ss(ans);
    string t;
    string ant;
    while(ss>>t){
        ant = t;    
    }
    return ant;
    
}

int termina(string &cad, vector<string> &suffix, char &a){
    int i = cad.size()-1;
    if(cad[i]=='s' or cad[i]=='S')cad = cad.substr(0,cad.size()-1);
    For(i,suffix.size()){
        if(cad.size()>= suffix[i].size()){
          //  D(cad.substr(cad.size()-suffix[i].size()));
            if(suffix[i]== cad.substr(cad.size()-suffix[i].size())){
                a = i+'A';
                return true;
            }
        }
    }
    return false;
}

int valid(string cad){
    if(cad.size()!=14) return false;
    if(cad == "ABBAABBACDECDE" or cad=="ABBAABBACDEDCE" or cad == "ABBAABBACDCDCD") return true;
    return false;
}

int main(){
  string mio;
  string ans;
  string name;
  int primero = 1;
  while(getline(cin,mio)){
      vector<string> sufijos = sufi(mio);
      getline(cin,mio);
      name= mio;
      int paila = true;
      ans="";
      while(getline(cin,mio) and mio.size()!=0){
        char actual;
        mio = limpiar(mio);
        if(termina(mio,sufijos,actual)){
            ans.push_back(actual);
        }else{
            paila = false;
        }
      }
      if(primero)primero=0;
      else cout<<endl;
      if(valid(ans) and paila){
        cout<<name<<": "<<ans;
      }else{
        cout<<name<<": Not a chance!";
      }
      
  }
  
    return 0;
}

