
### Topic

    Matrix exponentiation.


### Key Idea

Let's write the length function as a matrix multiplication,
if you are not familiar with this concept, read [this](http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html) first:

    |0 1| x |a0| = |a1| = |b0     |
    |1 1|   |b0|   |b1|   |a0 + b0|

In this form, the Nth state of the function can be computed as:

    |0 1| ^ N x |a0|
    |1 1|       |b0|

We know that:

    |0 1| ^ N x |a0| = |a b| x |a0| = |bn |
    |1 1|       |b0|   |c d|   |b0|   |X  |

and

    |0 1| ^ M x |a0| = |ap bp| x |a0| = |bn |
    |1 1|       |b0|   |cp dp|   |b0|   |Y  |


At this moment we have a system of two equations with two unkowns:

    X = c * a0 + d * b0
    Y = cp * a0 + dp * b0

We can find a0 and b0 using the [Cramer's rule](http://en.wikipedia.org/wiki/Cramer%27s_rule)
and finally compute the answer as:

    |0 1| ^ K x |a0|
    |1 1|       |b0|


### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1052)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1052&language=english&type=pdf)

