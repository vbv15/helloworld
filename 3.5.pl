%3.5 Multiplication of numbers of list.


%rule

mul([],X):- X = empty.
mul([X],X):-!.
mul([H|T],X):-mul(T,Y),X is Y*H.