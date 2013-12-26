### Topic.

    Number Theory.

### Key idea.

    We have:
        C*Q + L = P
    So the problem is to find all divisors of C*Q (equals to P - L).

    There are two approaches to solve this problem. The first just iterate until sqrt(N) and add to the list all "i" such that n%i == 0, also we have to add n/i.
    Take care with the case i = n/i, you must not add repeated values.

    The second approach is not more complex. First compute the prime fatorization and generate two list, primes and exponents. Then you can find all the divisors recursively.

    Both approaches have the same asymptotic complexity O(sqrt(n)), but the second method is significantly faster.

### Problem source.

  [1014 - Ifter Party](http://lightoj.com/volume_showproblem.php?problem=1014)
