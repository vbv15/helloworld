power(X,0,1):-!.
power(X,1,X):-!.
power(X,Y,Z):-pow(X,Y,1,Z).
pow(X,1,Z,R):-R is Z*X,!.
pow(X,Y,Z,R):-Y>1,Y1 is Y-1,Z1 is Z*X,pow(X,Y1,Z1,R).
