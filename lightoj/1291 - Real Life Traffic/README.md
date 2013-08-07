#### Topics:
    Articulation, Bridge, Biconnected Component. 
    
#### Key idea:

Think in this case:

    5 4
    0 1
    0 2
    0 3
    0 4

Remove all bridges in the graph, then run a flood fill to identify the connected component for each node.

After that, the answer is ceil of CC/2 .

where CC is:
connected component, such that it have just one bridge.





