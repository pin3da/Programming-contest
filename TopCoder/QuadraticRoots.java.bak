// BEGIN CUT HERE
PROBLEM STATEMENT
A quadratic equation has the format ax^2 + bx + c = 0 where a != 0.
To solve this equation the quadratic formula is used:
x = (-b (+|-) sqrt(b^2 - 4ac)) / 2a , 
where (+|-) means plus or minus, sqrt means square root, and x is the solution.

Given a list of values for a, b and c your method will return a sorted int[] of
all integer solutions to the corresponding quadratic equations.  The sorted values should be in
ascending order with no repeats.  For example, if
    a = {1} ,
    b = {2,3} ,
and c = {2,1} ,
your method would have to solve the quadratic equations corresponding to all combinations of values from a, b and c.  This would amount to solving: 
 x^2 + 2x + 2 = 0  (Solutions : not integers)
 x^2 + 2x + 1 = 0  (Solutions : -1)
 x^2 + 3x + 2 = 0  (Solutions : -2,-1)  
 x^2 + 3x + 1 = 0  (Solutions : not integers)  .
Notice that all combinations have been tried.  The return value would be {-2,-1}.


DEFINITION
Class:QuadraticRoots
Method:findRoots
Parameters:int[], int[], int[]
Returns:int[]
Method signature:int[] findRoots(int[] a, int[] b, int[] c)


CONSTRAINTS
-a, b, and c will each contain between 1 and 50 elements inclusive.
-Each element of a will be nonzero, between -10000 and 10000 inclusive.
-Each element of b and c will be between -10000 and 10000 inclusive.
-The returned int[] will contain at most 100 elements.


EXAMPLES

0)
{1}
{2,3}
{2,1}

Returns: { -2,  -1 }

Example from above.

1)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
{1}
{1}

Returns: { }

No roots here.

2)
{1}
{0}
{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16}

Returns: { -4,  -3,  -2,  -1,  1,  2,  3,  4 }

3)
{1,1,2,2,3,3,4,4}
{1,1,2,2,3,3,4,4}
{1,1,2,2,3,3,4,4}

Returns: { -3,  -2,  -1 }

Tons of repeats.

4)
{1,10000,-10000}
{0,1,10000,-10000}
{0,1,10000,-10000}

Returns: { -10000,  -100,  -1,  0,  1,  100,  10000 }

// END CUT HERE
import java.util.*;
public class QuadraticRoots {
	public int[] findRoots(int[] a, int[] b, int[] c) {
		
	}
	public static void main(String[] args) {
		QuadraticRoots temp = new QuadraticRoots();
		System.out.println(temp.findRoots(int[] a, int[] b, int[] c));
	}
}
