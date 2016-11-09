member([X],X):-!.
member([H|T],X):-X=:=H,!.
member([H|T],X):-member(T,X).

inter(T,[],[]):-!.
inter([],T,[]):-!.

inter([H|T],L2,[H1|R]):-member(L2,H),not(member([H1|R],H)),H1 is H,inter(T,L2,R),!.
inter([H|T],L2,R):-inter(T,L2,R).
