%4.2

rev1([],A):-write(A).
rev1([H|T],A):-rev1(T,[H|A]).
rev(Z):-rev1(Z,[]).

