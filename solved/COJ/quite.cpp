using namespace std;
#include<iostream>
#include<cmath>
#include<cctype>
#include<string>


int main(){
    string cad;
    while(getline(cin,cad)){
        for(int i=0;i<cad.size();++i){
            cad[i] = tolower(cad[i]);
        }
        if(cad.find("problem")!=string::npos)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    
    }
    return 0;
}
