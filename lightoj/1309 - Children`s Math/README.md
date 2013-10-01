### Topics:

Parsing, Grammar.
    
### Key idea:

First remove the left recursion. Take care if you think convert this grammar into right recursive grammar, because this can change (indeed do) the associativity of the rules.

by example:

```cpp

int expression(ast &tree){
    int left = term(tree);
    if(top() == PLUS or top() == MINUS){
        token_type op = pop().t;
        int right = expression(tree);
        left = tree.add(left,right,op);
    }
    return left;
}
```

can be changed to:

```cpp
int expression(ast &tree){
    int left = term(tree);
    while(top() == PLUS or top() == MINUS){
        token_type op = pop().t;
        int right = term(tree);
        left = tree.add(left,right,op);
    }
    return left;
}
```

then try to simplify the ecuation to the form ax = b, and problem solved :D.
    
    
### Source Problem

http://lightoj.com/volume_showproblem.php?problem=1309
