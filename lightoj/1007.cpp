#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#define MP 5000001
using namespace std;

typedef long long int i64;
typedef unsigned long long int ull;
typedef vector < int >IV;

template < class T > string toStr (const T & x) {
		stringstream s;
		s << x;
		return s.str ();
}

#define Sc(t,v) static_cast<t>(v)
#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); v++)

						// Number Theory
#define ISCOMP(n)  (_c[(n)>>5]&(1<<((n)&31)))
#define SETCOMP(n) _c[(n)>>5]|=(1<<((n)&31))

namespace Num {
		const int MAX = 9000010;
		const int LMT = 3000;
		int _c[(MAX >> 5) + 1];
		IV primes;
		void primeSieve () {
				SETCOMP (0);
				SETCOMP (1);
				for (int i = 3; i <= LMT; i += 2)
						if (!ISCOMP (i))
								for (int j = i * i; j <= MAX; j += i + i)
										SETCOMP (j);
				primes.push_back (2);
				for (int i = 3; i <= MAX; i += 2)
						if (!ISCOMP (i))
								primes.push_back (i);
		}
}

ull phi[MP];
void phiSieve () {
		using Num::primes;
		for (int i = 0; i < MP; ++i)
				phi[i] = i;
		for (int i = 0; primes[i] <= 5000000; ++i) {
				phi[primes[i]] = primes[i] - 1;
				for (i64 j = 2 * primes[i]; j <= 5000000; j += primes[i]) {
						phi[j] = phi[j] * (primes[i] - 1);
						phi[j] = phi[j] / primes[i];
				}
		}

		for (int i = 1; i < MP; ++i) {
				phi[i] *= phi[i];
				phi[i] += phi[i - 1];
		}
}

int main () {
		Num::primeSieve ();
		phiSieve ();

		int T;
		scanf ("%d", &T);

		int ncase = 1;
		while (T--) {
				int inf, sup;
				scanf ("%d %d", &inf, &sup);
				printf ("Case %d: %llu\n", ncase++, phi[sup] - phi[inf - 1]);
		} return 0;
}
