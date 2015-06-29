
### Topic

    Segment tree, BIT, Fenwick tree, binary search


### Key Idea

Let A be an integer array such that A[i] = 1 if the element i is available, 0 otherwise.

query(pos):
  Find the smallest i such the summatory from j = 0 up to j = i is equals to pos.
  This can be done using a binary search over j and getting the sum
  from 0 to j using either a BIT or a seg tree. Wich leds us a complexity O(log ^ 2 (n)).

  You can also do the binary search directly on the segment tree. O(log(n)).

  remember update the val of A[j] = 0; after each query.

addVal(val):
  add this val to the end of the array and mark A[end] = 1.

### Problem source

[LighOJ](http://lightoj.com/volume_showproblem.php?problem=1087)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1087&language=english&type=pdf)
