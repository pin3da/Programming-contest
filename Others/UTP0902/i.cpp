/*
ManuelPineda, accepted.
*/
using namespace std;
#include<cstdio>
#include<cmath>
#include<algorithm>
#define TOL 1.0e-6
#define SUM(a,b) a.first + b.first
#define SUM1(a,b) a.second + b.second
#define RES(a,b) a.first - b.first
#define RES1(a,b) a.second - b.second
#define DET(a,b,c,d)  ((a)*(d)-(b)*(c))
#define CRAMER(a,b,x,c,d,y) (DET(x,b,y,d)/DET(a,b,c,d))

typedef pair<double ,double> pdd;

/*ort (a,x)=(-x,a)
	r= a+ort(c-b)
*/
pdd ort(pdd a, pdd b, pdd c){
	pdd r;
	pdd tmp;
	tmp.first = RES1(b,c);
	tmp.second = RES(c,b);
	r.first = SUM(a, tmp);
	r.second = SUM1(a,tmp);
	return r;
}

/* cramer para hallar escalar al igualar las ecucaciones vectoriales.
	res= a1+k(a2-a1).
*/
pdd intersection(pdd a1,pdd a2,pdd b1,pdd b2){
	double k = CRAMER(RES(a2,a1), RES(b2,b1), RES(b1,a1),RES1(a2,a1), RES1(b2,b1), RES1(b1,a1));
	pdd res(a1.first + k*(RES(a2,a1)), a1.second + k*(RES1(a2,a1)) );
	return res;	
}

/*
	lina a+ku, a:=punto, K:=escalar , u:= vector director
*/
pdd center(pdd a, pdd b,pdd c){
	pdd d,e;
	d.first=(SUM(a,b))/2.0;
	d.second=(SUM1(a,b))/2.0;
	e.first=(SUM(b,c))/2.0;
	e.second=(SUM1(b,c))/2.0;
	return intersection(d, ort(d,a,b),
						e, ort(e, b,c));
}

// Angulo entre dos lineas ab,ac.
double angle(pdd a,pdd b,pdd c){
	b.first -= a.first; b.second -= a.second;
  	c.first -= a.first; c.second -= a.second;
	double r= acos((b.first * c.first + b.second * c.second) / (hypot(b.first, b.second) * hypot(c.first, c.second)));
	if(isnan(r))return acos(-1);
  	return r;
}

bool precision(double f, double n) {
	n=360/n;
  return fabs(f/n - round(f/n)) < TOL;
}


int main(){
	const double pi= 180/acos(-1);
	int cas=0;
	pdd a,b,c,cent;
	double angles[3],hola;
   	while(1){       
    	if(scanf("%lf %lf",&a.first,&a.second)!=2) break;
    	scanf("%lf %lf",&b.first,&b.second);  
    	scanf("%lf %lf",&c.first,&c.second);
        cent=center(a,b,c);
		angles[0]=angle(cent,a,b)*pi;
		angles[1]=angle(cent,b,c)*pi;
		angles[2]=360-angles[0]-angles[1];
		//gcd a fuerza bruta :P
		for (int n=3; n <=1000; n++)
    		if (precision(angles[0],n) && precision(angles[1], n) && precision(angles[2],n)) {
        		printf("%i\n", n);
        		break;
      		}
	}
	return 0;
}
