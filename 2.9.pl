%Implementing the mamber clause.
member([X],X):-!.
member([H|T],X):-X=:=H;member(T,X).
