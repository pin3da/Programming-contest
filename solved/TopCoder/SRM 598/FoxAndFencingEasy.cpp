using namespace std;
#include<bits/stdc++.h>


class FoxAndFencingEasy {
	public:
	string WhoCanWin(int mov1, int mov2, int d) {
		if(d <= mov1) return "Ciel";
		
		if(mov1*2 < mov2) return "Liss";
		if(mov2*2 < mov1) return "Ciel";
		return "Draw";
	}
};
