/**
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=208

Manuel Pineda
accepted, 0.016
*/

using namespace std;
#include<iostream>
#include<string>

int main(){
	string cad;
	int pin=1;
	while(getline(cin,cad)){
		for(int i = 0; i < cad.size();++i){
			if(cad[i]=='"' && pin){cout<<"``";pin= !pin;}
			else if(cad[i]=='"' && !pin){cout<<"''";pin= !pin;}
			else cout<<cad[i];
		}
		cout<<endl;
	}
	
	return 0;
}
