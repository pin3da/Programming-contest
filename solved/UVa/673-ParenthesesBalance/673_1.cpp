//recursive sol
using namespace std;
#include<iostream>
#include<string>

int check(string cad){
	//Empty string is valid.
	if(cad=="")return 1;
	int a=0, b=0, i;
	//if A is valid and B is valid, AB is valid
	for (i = 0; i<cad.size(); i++){
		if (cad[i] == '(') a++;
	    if (cad[i] == ')') a--;
	    if (cad[i] == '[') b++;
	    if (cad[i] == ']') b--;

	    if (a == 0 && b == 0){
	      break;
	    }

  	}

	if (i < cad.size()-1){
   		return (check(cad.substr(0, i+1)) && check(cad.substr(i+1)));
	}
	//If A is valid, (A) or [A] too
	char f=cad[0];
	char e=cad[cad.size()-1];
	if( (f =='(' && e== ')') || (f=='[' && e== ']'))
		return check(cad.substr(1,cad.size()-2 ));
	//Paila 
	return 0;
}

int main(){
	string cad;
	int numcas;
	scanf("%d\n",&numcas);
	while(numcas--){
		cin>>cad;
		cout<<(check(cad)?"Yes":"No")<<endl;
	}
	return 0;
}
