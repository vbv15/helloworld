%3.3 Max of numbers of list.


%rule

max2(X,Y,Z):- X>Y, Z is X; Z is Y.

max([],X):- X is empty.
max([X],X).
max([H|T],X):-max(T,Y),max2(Y,H,Z),X is Z.
