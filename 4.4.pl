gcd(X,X,X):-!.
gcd(X,Y,Z):-X>Y, X1 is X-Y,gcd(X1,Y,Z),!.
gcd(X,Y,Z):-Y>X, Y1 is Y-X,gcd(X,Y1,Z).
