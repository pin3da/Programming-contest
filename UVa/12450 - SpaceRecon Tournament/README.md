#### Topics:
    Bruteforce, implementation.
    
#### Key Idea:

Note than M is at most 10, therefore R too.
Suppose every R posible and based in this information calculate the max round in which 
each player is still alive.
Then check if this distribution is consistent, for this, make sure that in each round
the number of players remaining are half the previous. (Except for the last)
i.e. 16 8 4 2 1 1 is a correct distribution.


