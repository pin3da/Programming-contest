### Topic

    Graphs, Bellman - Ford.

### Key Idea.

  Compute the minimum earning to all nodes from 1.
  For each node which can be reached with negative earning, all its descendants can be reached with negative earning too. So, perform a dfs to mark all nodes with negative earning.
  For each query, if the node is reachable with negative earning, or not reachable or with earning < 3, puts '?'
  otherwise puts the total earning form 1.

### Problem source

  [1074 - Extended Traffic](http://lightoj.com/volume_showproblem.php?problem=1074)

### Notes.

  The implementation of bellman-ford algorithm was written thinking in this problem in particular, I don't recommend it for other problems because it might be not clear.


