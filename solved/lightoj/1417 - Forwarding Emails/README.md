### Topics

    Strongly connected componnents, dfs.


### Key idea

First, note that the graph have no restrictions, so we can find cycles and make the problem a bit more complex.

To eliminate the cycles, we can use the Tarjan's algorithm to find the scc [Strongly connected component](http://en.wikipedia.org/wiki/Strongly_connected_component) of each node, then we'll keep an array nodes wich holds the number of nodes in each scc.

Let's build a directed acyclic graph with the above information, just perform a dfs in the original graph and for each edge u -> v which scc[u]  != scc[v] draw an edge in the new graph from u to v.

Finally in the directed acyclic graph we can calculate the maximum number of reached nodes from a specific node with a traversal in the graph. Use memoization, in this way you don't  recalculations.

### Useful link

  [Tarjan's Algorithm](http://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)

### Problem Source

  [1417 - Forwarding Emails](http://lightoj.com/volume_showproblem.php?problem=1417)


