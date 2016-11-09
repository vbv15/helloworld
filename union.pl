member([X],X):-!.
member([H|T],X):-X=:=H,!.
member([H|T],X):-member(T,X).

uni(T,[],T):-!.
uni([],T,T):-!.

uni([H|T],L2,[H1|R]):-not(member(L2,H)),H1 is H,uni(T,L2,R),!.
uni([H|T],L2,R):-uni(T,L2,R).
