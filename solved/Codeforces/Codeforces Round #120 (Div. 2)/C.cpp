// http://codeforces.com/contest/190/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
template<class T>
int to_int(T t){int r; stringstream ss; ss<<t; ss>>r; return r;}
string output;
vector<string> input;
int _i;


bool parse(){
    if(_i >=  input.size()) return false;
    if(input[_i]=="int"){
        output += "int";
    }else{
        output += "pair<";
        _i++;
        bool a = parse();
        output += ",";
        _i++;
        bool b = parse();
        output += ">";
        return a && b;
    }
    return true;
}

int main(){ ___

    string buffer;
    while(getline(cin,buffer)){
        int n = to_int(buffer);
        getline(cin,buffer);
        stringstream ss(buffer);
        input.clear();
        while(ss>>buffer)
            input.push_back(buffer);
        
        
        output = "";
        _i = 0;
        
        if(parse() and _i == input.size()-1)
            cout<<output<<endl;
        else
            cout<<"Error occurred"<<endl;
    }
   
    return 0;
}