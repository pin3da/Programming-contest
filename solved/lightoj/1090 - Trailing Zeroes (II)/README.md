
### Topic

    Math


### Key Idea

Let's express the equation in terms of factorials:

    (n! / (r! * (n - r)!)) * p ^ q

The number of trailing zeroes is equals to the exponent of 10 in the above expression.

How can we get that value ?

10 = 5 * 2, so we just need to compute the minimum between the exponent of 5 and the exponent of 2.

Finding the exponent of X {2, 5} in p ^ q is trivial, just compute the exponent of X in p and then
multiply it by q.

Finding the exponent of X {2, 5} in n! could be a little more complex.
[Here](http://math.stackexchange.com/questions/141196/highest-power-of-a-prime-p-dividing-n)
is a good explanation of how to compute that value.


### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1090)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1090&language=english&type=pdf)
