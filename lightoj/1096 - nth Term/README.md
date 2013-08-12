#### Topics.
    Matrix exponentitation, Maths.
    
#### Key idea.
    
This problem can be solved using matrix exponentitation, for this we need
represent the recurrence relation as a matrix that allows us calculate an state
based in previous state.

think in this recurrence: f(n) = f(n-1) +  2f(n-1)

We need to find a matrix M such that:


    M x |  f(n)  | = | f(n+1) |
        | f(n-1) |   |  f(n)  |
        
    
therefore, the first row of M must be {1 2}. to ensure that f(n) = f(n-1) + 2f(n-1).
the second row is {1,0}.... 1*f(n-1) + 0*f(n-2) =  f(n-1).


    How to calculate f(n):
    ======================


        M x |  f(n)  | = | f(n+1) |
            | f(n-1) |   |  f(n)  |

	        ............(1)

        How about we multiply M multiple times? Like this:


        M x M x |  f(n)  | = | f(n+1) |
                | f(n-1) |   |  f(n)  |


        Replacing from (1):


        M x M x |  f(n)  | = M x | f(n+1) | = | f(n+2) |
                | f(n-1) |       |  f(n)  |   | f(n+1) |


        So, we finally get:


        M^2 x |  f(n)  | = | f(n+2) |
              | f(n-1) |   | f(n+1) |


        Similarly we can show:




        M^3 x |  f(n)  | = | f(n+3) |
              | f(n-1) |   | f(n+2) |


        M^4 x |  f(n)  | = | f(n+4) |
              | f(n-1) |   | f(n+3) |


        ...............................
        ...............................
        ...............................


        M^k x |  f(n)  | = | f(n+k) |
              | f(n-1) |   |f(n+k-1)|
              
              
For clarity see the follow post http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html , 
where is explained in detail.


