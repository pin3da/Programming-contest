/*
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=131
Manuel Pineda.
Accepted - runtime: 1.248
*/
using namespace std;
#include<cctype>
#include<iostream>
#include<algorithm>
#include<set>

bool fncomp(string a, string b){
	for(int i=0;i<a.size();i++){
		if(tolower(a[i])<tolower(b[i]))
			return true;
		else if(tolower(a[i])>tolower(b[i]))
			return false;
		else if(a[i]!=b[i])
			return a[i]<b[i];
	}
//	return (int)a[i]< (int)b[i];
}


int main (){
	string cad;
	int numcas,len;
	bool(*fn_pt)(string,string) = fncomp;
  	set<string,bool(*)(string,string)> myset (fn_pt);
//	set<string> myset;
	set<string>::iterator it;
	cin>>numcas;
	while(numcas--){
		cin>>cad;
		len=cad.size();
		sort(cad.begin(),cad.begin()+len);
		myset.insert(cad);
  		while (next_permutation(cad.begin(),cad.begin()+len))
			myset.insert(cad);
		for (it=myset.begin(); it!=myset.end(); it++)
				cout<<*it<<endl;
		myset.clear();
	}
  	return 0;
}
