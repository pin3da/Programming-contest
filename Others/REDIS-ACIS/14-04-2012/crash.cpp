using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_double 1.79769e+308
#define For(i,k) for(int i=0; i< (k) ; ++i) 

#define FILE_IN "crash"

const double EPS = 1e-7;
int cmp(double x, double y = 0, double tol = EPS){
	return (x <= y + tol) ? ( x+ tol < y) ? -1 : 0 : 1;
}

typedef pair<double, double > pdd;
typedef pair<double,pdd> circle;

double distanceC(circle a,circle b){
	pdd c1 = a.second;
	pdd c2 = b.second;
	double f1,f2;
	f1 = c1.first - c2.first;
	f2 =  c1.second - c2.second;
	return sqrt(f1*f1 + f2*f2);
}

double newRadio(circle a,circle b){
	return sqrt(a.first*a.first + b.first*b.first);
}

int valid(circle a,circle b){
	//if( !(cmp(a.first,distanceC(a,b)) == -1 ) || !(cmp(b.first,distanceC(a,b)) == -1 ) ){
	if(a.first>= distanceC(a,b) or b.first>= distanceC(a,b) ){
		return 1;
	}else{
	return 0;
     }
}

pdd midPoint(circle a,circle b){
	pdd tmp( (a.second.first + b.second.first)/2.0 , (a.second.second + b.second.second)/2.0);
	
	return tmp;
}


circle merge(circle a, circle b){
	circle antonio;
	if(valid(a,b)){
		antonio.first = newRadio(a,b);
		antonio.second = midPoint(a,b);
		return antonio;
	}else{
		antonio.first = 0;
		return antonio;
	}

}

vector<circle> vec;
vector<circle> mg;

void smerg(){
	circle tmp = mg[0];
	for(int i=1; i<mg.size(); i++){
		circle kilo = merge(tmp,mg[i]);
		if(kilo.first != 0){
			mg.erase(mg.begin()+i);
			mg.erase(mg.begin());
			mg.insert(mg.begin(),kilo);
			smerg();
		}
	}
	for(int i=0; i<mg.size(); i++){
		vec.insert(vec.begin(),mg[i]);
	}
}


void super(){
	circle tmp = vec[0];
	int pin = 0;
	mg.clear();
	for(int i=1; i<vec.size(); i++){		
		circle kilo = merge(tmp,vec[i]);
		if(kilo.first != 0){
			mg.insert(mg.begin(),vec[i]);
			vec.erase(vec.begin()+i);
			i--;
			pin = 1;
		}
	}
	vec.erase(vec.begin());
	mg.insert(mg.begin(),vec[0]);
	smerg();
	if(pin)super();
	return;
}

int main(){
	//freopen(FILE_IN ".in","r",stdin);
	int	numC;
	int a,b,c;
	while(true){
		cin>>numC;
		if(numC==0)break;
		vec.clear();
		while(numC--){
			cin>>a>>b>>c;
			pdd pos(a,b);
			circle tmp;
			tmp.first = c;
			tmp.second = pos;
			vec.insert(vec.begin(),tmp);
			super();
			//smerg();
		}
		cout<<vec.size()<<endl;	
	}
	
	return 0;
}
