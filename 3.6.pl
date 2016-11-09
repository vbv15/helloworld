%3.6 Count number of elements of list.


%rule

len([],X):- X is 0.
len([H|T],X):-len(T,Y),X is Y+1.