using namespace std;
#include<bits/stdc++.h>


class TheArithmeticProgression {
	public:
	double minimumChange(int a, int b, int c) {
        double ans = (c + a)/2.0;
        return fabs(ans-b);
	}
};
