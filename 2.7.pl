% count the number of atoms in a list, i.e. if a list is present as an element of a list, then dont count it as 1, but count the no. of its

check_if_list(X):- !,X \=[].
check_if_list([]):-!.
check_if_list([_|T]):-check_if_list(T).

count([],0):-!.
count([H|T],X):-check_if_list(H),count(H,Y),count(T,X1),X is X1+Y,!.
count([H|T],X):-count(T,X1),X is X1+1.
