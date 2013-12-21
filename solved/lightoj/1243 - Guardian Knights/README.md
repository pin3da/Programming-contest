### Topics:
    Min cost max flow.

#### Key idea:

Connect each knight with the source with capacity equal to the number of mills that knight can look after, and cost 0.
Connect each knight with each mill. The cost will be the same defined in the problem statement, with capacity 1.
Connect each mill to the sink with capacity 1 and cost 0.

When you build this graph, just use an algorithm to find the min cost/max flow between source and sink.

#### Notes:

in 1243.cpp i tried to solve the problem using bellman-ford algorithm to find the best path (step necessary in the MCMF algorithm)
but is not fast enought.

in 1243_dijkstra.cpp i use dijkstra algorithm instead of bellman-ford. The running time decreased from 2.980 to 0.512
