### Topic

    Dynamic Programming

### Key Idea

the first thing to note is that this problem does not works recursively. Apparently is not fast enough for POJ.

I solve this problem in two different ways.

Using LCS:

Note that the LCS between the string and reversed string, gives you the "Longest possible palindrome" (i don't know how is really named), with this you can compute the answer by : String_size - LPP.

Computing the LPP directly:

You can find too the LPP without LCS, for this i wrote a dp in the following way:


dp(i,L) => LPP starting  in "i" with length "L"

dp(i,L) = Min { dp(i+1, L-2)  ,  dp(i+1, L-1) , dp(i, L-1) }

### Problem source

  [1159 - Palindrome](http://poj.org/problem?id=1159)
