%To check if entered argument is a list or not.

check_if_list(X):- !,X \=[].
check_if_list([]).
check_if_list([H|T]):-check_if_list(T).
