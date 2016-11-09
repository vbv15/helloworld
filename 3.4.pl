%3.4 Sum of numbers of list.


%rule

sum([],X):- X is 0.
sum([H|T],X):-sum(T,Y),X is Y+H.
