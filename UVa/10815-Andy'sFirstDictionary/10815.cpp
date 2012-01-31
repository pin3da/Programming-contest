/**
Acepted.
runtime: 0.040
*/

using namespace std;
#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<cctype>

int main(){
        string cad,cad2;
        set<string> setwords;
        set<string>::iterator it;
        stringstream stream;
        int i;
        
        while(getline(cin,cad)){
             for(i=0;i<cad.size();i++){
                 if(isalpha(cad[i]))
                    cad[i]=tolower(cad[i]);
                 else
                     cad[i]=' ';
             }
             stringstream stream(cad);
             while(stream>>cad2)
                 setwords.insert(cad2);   
        }
        for(it=setwords.begin();it!=setwords.end();it++)
                 cout<<*it<<endl;    
}
