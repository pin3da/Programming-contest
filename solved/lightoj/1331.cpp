/**
* Solucion de Alejandro Diaz.
* Estudiante matematicas
* Universidad tecnologica de pereira
*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const double  PI = acos(-1);

int main(){
    int Case,i;
    double AR2, AR3, AR1, At, aR1, aR2, aR3, aa, bb, cc, sPer, R1, R2, R3, rad, Res, p, s, t;

	cin>>Case;
	for(i=0; i!=Case; i++){
		cin>>R1>>R2>>R3;
		sPer = (R1+R2+R3);//semiperímetro
		rad=sPer*(sPer-(R1+R2))*(sPer-(R3+R2))*(sPer-(R1+R3));
		At = sqrt(rad);//área del triángulo
		p=(R1+R3);//las medidas de los lados
		s=(R1+R2);
		t=(R2+R3);
		cc=p*p;//los cuadrados de los lados, sólo por simplificar
		bb=s*s;
		aa=t*t;
		aR2= acos((-aa-bb+cc)/(-2*t*s));//ángulo
		AR2=(R2*R2)*(aR2)/2;//área de una región

		aR3= acos((cc+aa-bb)/(2*t*p));
		AR3=(R3*R3)*(aR3)/2;

		aR1= acos((bb+cc-aa)/(2*s*p));
		AR1=(R1*R1)*(aR1)/2;


		Res=At-(AR1+AR2+AR3);//la diferencia de áreas
		printf("Case %d: %.10lf\n",i+1,Res);
                   
     }
	return 0;
}
