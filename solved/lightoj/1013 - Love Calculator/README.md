### Topic

    Dynammic programming


### Key Idea

Citing the Leonardo's post:

... For example, when solving the LCS problem you may formulate a D.P. function like this:

f(A, i, B, j): The length of the LCS for A(i) and B(j), where A and B are
               strings, i and j are integers, and S(n) is the notation for the
               prefix of S of length n.


Now, the D.P. relation for f tipically involves checking if A_(i-1) == B_(j-1) (the last characters of each string are equal), or using the minimum between f(A, i-1, B, j) and f(A, i, B, j-1), and so on.

For this problem, think now of two different, but somewhat related D.P. functions:

g(A, i, B, j): The length of shortest string that contains A(i) and B(j) as
               subsequences.

h(A, i, B, j): The number of shortest strings that contain A(i) and B(i) as
               subsequences.


Take your time to think about how those functions can be defined. Notice that, for example, g can be useful for calculating h.

### Problem source

[lightOJ](http://lightoj.com/volume_showproblem.php?problem=1013)
[PDF](http://lightoj.com/volume_showproblem.php?problem=1013&language=english&type=pdf)
