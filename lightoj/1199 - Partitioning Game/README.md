### Topic.
    Sprague-Grundy Number. Nim.
    
    
### Key idea.
    
    Let S be a state, and t1,t2,...,tn be states can be reached from S using a single move.
    
    The Grundy number g(S) of is the smallest nonnegative integer that doesn’t appear in
    {g(t1),g(t2),...,g(tn)}.
    
    In this problem the states 0,1,2 are not in winning position, so their grundy number is 0.
    
    For every number i greater than 2, we can represent it by a + b, such that a < b and a != b.
    Then the grundy number of i let be:
    
    g(i) = smallest number which is not formed by a xor b.  (Mex operation between two piles).
    
    
    Let denote the size of pile N by Pn.
    
    Finally, just compute nim = g(P1) ^ g(P2) ^ ... ^ g(Pn).
    
    winner = (nim==0)? Bob : Alice.
