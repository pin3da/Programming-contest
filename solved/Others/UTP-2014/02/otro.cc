// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M,S,F,t,l,r,t0 =1;
	cin >> N >> M >> S >> F;
	for(int i =0; i < M; i++) {
		cin >> t >> l >> r;
		while(t0 < t && S != F) {
			if(S < F) {cout << "R"; S++;}
			else {cout << "L"; S--;}
			t0++;}
    cout<<endl<<S<<endl;
		if(S < F) {
			if(S > r || S+1 < l) {cout << "R"; S++;}
			else cout << "X";}
		if(S > F) {
      cout<<r<<" "<<l<<endl;
			if(S-1 > r || S < l) {cout << "L"; S--;}
			else cout << "X";}
		t0++;
		if(S == F) break;}
	while(S != F) {
		if(S > F) {cout << "L"; S--;}
		else {cout << "R"; S++;}}
	cout << "\n";
    return 0;}

// look at my code
// my code is amazing
