### Topics

    Expected Value, matrix exponentiation

### Key Idea

I really like the problem because I'd not solved a problem like this.

At first we can think in a classic dynamic programming problem, something like:


    dp(99) = 0;

    dp(0) = ( dp(1) + dp(2) + dp(3) + dp(4) + dp(5) + dp(6) + dp(7) ) * 1.0 / 6.0 + 1


But there is a problem with the snakes and ladders; For example we can obtain something like:


  dp(20) = ( dp(21) + dp(22) + dp(5) + dp(24) + dp(25) + dp(88) + dp(27) ) * 1.0 / 6.0 + 1


from the input data. (5 is because there is a snake, and 88 is because there is a ladder).

To solve this (first) problem, let's define to(i) = i for every 'normal' cell, and to(a) = b, for those cells with snake or ladder.

Now the problem could be written like this:


```c++
for (int j = 1; j <=6; ++j) {
   dp[i] += dp[to[i]] / 6.0;
}
dp[i] += 1.0;
```

At this moment if for each i, to[i] is greater than i, we could solve the problem in a standard way (using bottom up approach or something like that). But unfortunatelly, is not the case.

Here comes the most interesting part.

If we write the problem as a system of equations, we can use Gaussian elimination (or Gauss-Jordan) to solve it.

suppose a problem with 3 states which depend on each other:

    dp(1) = dp(2) / 6  + dp(3) + 1
    dp(2) = dp(1)  / 6 + dp(3) + 1
    dp(3) = 0

Let's arrange the system of equations:

    AX = B


    1        -1/6      -1 = 1
    -1/6     1         -1 = 1
    0         0          1 = 0

A is equal to

    1        -1/6      -1
    -1/6     1         -1
    0         0          1


X is equal to

    dp(1)
    dp(2)
    dp(3)

And B is equal to

    1
    1
    0


After Gaussian Elimination we obtain:

    dp(1) = 1.2
    dp(2) = 1.2
    dp(3) = 0

The original problem could be solved in the same way, just a system of 100 equations instead of 3

### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1151)

### Notes

[Gauss-Jordan Code](http://stanford.edu/~liszt90/acm/notebook.html#file14)
