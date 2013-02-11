using namespace std;
#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>

#define D(x) cout<< #x " = "<<x<<endl


vector<int> todos;

int main(){
    string cad;
    int mm=-1;
    while(getline(cin,cad)){
        todos.push_back(cad.size());
        if((int)cad.size() > mm)mm=cad.size();
    }
    todos.erase(todos.end()-1);
    int ans=0;
    for(int i=0;i<todos.size();++i){
        ans+=((mm-todos[i])*(mm-todos[i]));
    }
    cout<<ans<<endl;;
    return 0;
}






