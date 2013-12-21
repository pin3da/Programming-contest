//iterative sol using STL stack
using namespace std;
#include<iostream>
#include<string>
#include<cstdio>
#include<stack>

int main(){
	string cad;
	int numcas,i;scanf("%d\n",&numcas);
	while(numcas--){
		getline(cin,cad);
		stack<char> stk;
		for(i=0;i<cad.size();i++){
			if(cad[i]=='(' or cad[i]=='[')stk.push(cad[i]);
			else if(!stk.empty() and ( (stk.top() == '[' and cad[i] == ']') or (stk.top() == '(' and cad[i] == ')') ) ) stk.pop();
			else break;
		}
		if(i==cad.size() && stk.empty())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
