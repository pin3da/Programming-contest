using namespace std;
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

#define For(i,n) for(int  i= 0 ; i<n;++i)
#define D(x) cout<< #x " = " <<(x)<<endl

string alphabet[20] = {"a","b","k","d","e","g","h","i","l","m","n","x","o","p","r","s","t","u","w","y"};

int get_index(string a){
    For(i,20){
        if(a==alphabet[i]) return i;
    }
}

int mycmp(string a,string b){
    int index = 0;
    while(a[index]==b[index])++index;
    string aa;aa+= a[index];
    string bb; bb+=b[index];
    return get_index(aa) < get_index(bb);
}

int main(){
    string cad;
    while(getline(cin,cad)){
        if(cad=="END")break;
        vector<string> todos;
        stringstream ss(cad);
        string t;
        int index = 0;
        map<string,string> mio;
        while(ss>>t){
            string k;
            For(i,t.size()-1){
                if(t[i]=='n' and t[i+1]=='g'){
                    k+='x';
                    i++;
                }else{
                    k+=t[i];
                }
            }
            if(t[t.size()-2]!='n' or t[t.size()-1]!='g') k+=t[t.size()-1];
            todos.push_back(k);
            mio[k] = t;
        }
        
        sort(todos.begin(),todos.end(),mycmp);
        
        For(i,todos.size()){
            if(i!=0)cout<<" ";
            cout<<mio[todos[i]];
        }
        cout<<endl;
        
    }
    return 0;
}

