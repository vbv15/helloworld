%Prolog program to append two lists.
app([],L2,L2):-!.
app([H|T],L2,[H|T1]):-app(T,L2,T1).
