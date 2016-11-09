%4.3

maxlist([],X):- write(empty).
maxlist([X],X):-!.
maxlist([H|T],Max):-maxlist(T,Y),max(Y,H,M),Max is M,!.
max(X,Y,M):-X>Y,M is X;M is Y.
