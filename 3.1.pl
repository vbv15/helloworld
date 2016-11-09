%3.1 Check pallindrome .

%rule

pal([]).
pal([Z]).

pal([H|T]):-tail(T,Y),Y=:=H, left(T,X), pal(X).

tail([X],X).
tail([H|T],X):- tail(T,Y),X is Y.

left([X],[]).
left([H|T],[H|T1]):- left(T,T1).
