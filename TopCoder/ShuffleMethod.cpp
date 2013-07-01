// BEGIN CUT HERE
PROBLEM STATEMENT
You will be given a vector <int> twoShuffle with k elements denoting a method for shuffling a deck of cards.  The deck in question will have k cards numbered 1 through k inclusive.  Initially, all of the cards in the deck are arranged in ascending order.  The ith (1-based) element of twoShuffle describes which card is in position i (1-based) after 2 identical shuffling procedures have completed.  You will return a vector <int> that is exactly like the input, except it describes what a single shuffle would do. A shuffling procedure describes how the relative positions of the cards will change due to the shuffle.  More precisely, if element s of a shuffling procedure is p, then the card that was in position p ends up in position s (again, all 1-based).  For example,
	twoShuffle = {3,4,1,2}
means that after two shuffles 
	the deck   1,2,3,4   would become  3,4,1,2.
You would return {2,3,4,1} since: 
	the deck 1,2,3,4  -    after one shuffle  - 2,3,4,1 
		          - after another shuffle - 3,4,1,2.
If there are no possible solutions, return an empty vector <int>.  If there is more than 1 possible solution, return the one that comes first lexicographically.  A shuffle X comes lexicographically before a shuffle Y if there is a position j such that, X[i]=Y[i] for all i<j, and X[j]<Y[j].

DEFINITION
Class:ShuffleMethod
Method:oneTime
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> oneTime(vector <int> twoShuffle)


CONSTRAINTS
-twoShuffle will contain between 3 and 50 elements inclusive.
-Each element of twoShuffle will be between 1 and k inclusive, where k is the number of elements in twoShuffle.
-twoShuffle will contain no duplicate elements.


EXAMPLES

0)
{3,4,1,2}

Returns: { 2,  3,  4,  1 }

The example from above.

1)
{1,2,3,4}

Returns: { 1,  2,  3,  4 }

The cards are unshuffled.  Since 1,2,3,4 is a valid solution, and is lexicographically first, it is the return value.  2,1,4,3 is another valid solution, but it does not come before 1,2,3,4 lexicographically.

2)
{5,1,2,3,4}

Returns: { 3,  4,  5,  1,  2 }

Using the shuffle 3,4,5,1,2 twice we see that 
1 -> 3 -> 5
2 -> 4 -> 1
3 -> 5 -> 2
4 -> 1 -> 3
5 -> 2 -> 4

In other words, the deck is transformed as follows:
1,2,3,4,5 -> 3,4,5,2,3 -> 5,1,2,3,4

3)
{2,4,6,5,1,8,10,9,3,12,11,13,7,15,16,17,14}

Returns: { 3,  6,  2,  8,  9,  4,  14,  5,  1,  15,  11,  16,  17,  10,  12,  13,  7 }

4)
{2,4,6,5,1,8,10,9,3,12,11,13,7}

Returns: { }

5)
{10,9,12,8,13,3,4,1,5,11,6,2,7}

Returns: { 9,  1,  4,  12,  11,  7,  3,  2,  10,  5,  13,  8,  6 }

// END CUT HERE
#line 74 "ShuffleMethod.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
class ShuffleMethod {
	public:
	vector <int> oneTime(vector <int> twoShuffle) {
		
	}
};
