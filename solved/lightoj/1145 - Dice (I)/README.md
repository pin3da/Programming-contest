### Topic

    Dynamic Programming

### Key Idea

I'll not explain the recurrence function in this time, but is something
like that:

    dp (i, s) :
      if (s < 0)
        return 0
      if (i == N)
        return (s  == 0) ? 1 : 0
      return sum (dp(i + 1, s - k)) // k from 1 up to K

Note that we just need the index (i + 1) to calculate i, so we can keep only 2 positions
in the array.

Beside this, we can compute the inner sum faster with an [Integral image](http://en.wikipedia.org/wiki/Summed_area_table) (is something like inclusion-exclusion principle).


### Problem source

[1145 - Dice (I) ](http://lightoj.com/volume_showproblem.php?problem=1145)
