%Comparing two words.
check(W,X):-name(W,Y),name(X,Z),compare(Y,Z).
compare([_],[]):-write(greater),!.
compare([H1],[H2]):-H1>H2,write(greater),!.
compare([H1],[H2]):-H1=:=H2,write(equal),!.
compare([H1|T1],[H2|T2]):-H1>H2,write(greater),!;H1=:=H2,compare(T1,T2).
