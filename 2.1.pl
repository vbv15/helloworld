%Add an item at nth position in the list

len([],X):- X is 0.
len([H|T],X):-len(T,Y),X is Y+1.

add(1,X,L,[X|L]):-!.
add(Pos,X,[H|T],[H|T1]):-Pos1 is Pos-1,add(Pos1,X,T,T1).

add_to_list(Pos,X,Z,R):-len(Z,T),Pos=<T,!,add(Pos,X,Z,R).
